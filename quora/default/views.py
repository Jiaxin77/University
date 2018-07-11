from django.shortcuts import render
from django.http import HttpResponseRedirect,JsonResponse
from django.contrib.auth import authenticate,login,logout
from django.contrib.auth.decorators import login_required
from default.models import UserProfile,Question,Answer,Notice
from django.contrib.auth.models import User
from default.env import QusetionForm,ReplyForm
# Create your views here.

@login_required()
def delete_view(request):#取消关注
    followed_id = request.GET['followedid']
    follower_id = request.GET['followerid']
    follower = UserProfile.objects.get(user_id=follower_id)
    followed = UserProfile.objects.get(user_id=followed_id)
    follower.follower.remove(followed)
    followed.followed.remove(follower)
    return HttpResponseRedirect("/myfocus/?userid="+str(follower_id))


def home_view(request):#访问主页
    hotqlist = Question.objects.order_by('-viewscount')[0:10]
    if request.user.is_authenticated():
        user_id = request.GET['userid']
        return render(request,"hotquestion.html",{'userid':user_id,'hotqlist':hotqlist})
    else:
        user_id = str(-1)
        return render(request,"hotquestion.html",{'userid':user_id,'hotqlist':hotqlist})

@login_required()
def follow_view(request):#关注 ajax前台
    if request.method == "POST":
        followed_id = request.POST['followedid']
        follower_id = request.POST['followerid']

        #print(follower_id)
        #print(followed_id)
        if follower_id == followed_id:#关注的是本人 不能关注
            status = 0
        elif follower_id == "-1":#未登陆 转到登陆页面
            #print(follower_id)
            return HttpResponseRedirect("/login/")
        else:
            follower = UserProfile.objects.get(user_id=follower_id)  # 关注者加入被关注者信息
            followed = UserProfile.objects.get(user_id=followed_id)  # 被关注者加入对应关系
            if follower in followed.followed.all():#已关注
                status = 1
            else:#未关注 关注人数加1
                status = 1
                followed.followedcount = followed.followedcount + 1
                follower.follower.add(followed)
                followed.followed.add(follower)
                followed.save()
        result = {}
        result['status'] = status
    return JsonResponse(result)
'''
        followed_id = request.GET['followedid']
        follower_id = request.GET['followerid']
        q_id = request.GET['questionid']
        follower = UserProfile.objects.get(user_id=follower_id)#关注者加入被关注者信息
        followed = UserProfile.objects.get(id=followed_id)#被关注者加入对应关系
        if follower_id == followed_id:
            status = 0
        else:
            if follower in followed.followed.all():
                status = 1
            else:
                status = 1
                followed.followedcount=followed.followedcount+1
                follower.follower.add(followed)
                followed.followed.add(follower)
                followed.save()
        return HttpResponseRedirect("/questiondetail/?questionid="+str(q_id)+"&&userid="+str(follower_id))
'''
def getquestionlist_view(request):#展示消息列表
    if request.method == 'GET':
        user_id = request.GET['userid']
        list = Question.objects.all()
        return render(request,"QList.html",{'list':list,'userid':user_id})

@login_required()
def getnoticelist_view(request):#提示列表
    user_id = request.GET['userid']
    notice_list = Notice.objects.filter(receiver=user_id,status=False)
    return render(request,"noticelist.html",{'notice_list':notice_list,'userid':user_id})


def questiondetail_view(request):#问题细节
    if request.method == 'GET':#显示问题
        q_id = request.GET['questionid']
        user_id = request.GET['userid']
        q = Question.objects.get(id=q_id)
        q.viewscount=q.viewscount+1
        q.save()
        list = Answer.objects.filter(question_id=q_id)
        objPost = ReplyForm()
        if user_id == "-1": #0未关注 1关注
            status = 0
        else:
            follower = UserProfile.objects.get(user_id=user_id)
            followed = q.author
            if follower in followed.followed.all():
                status = 1
            else:
                status = 0
        return render(request, "question.html", { 'q':q,'list':list,'obj':objPost,'userid':user_id,'status':status})
    else:#回复问题
        user_id = request.GET['userid']
        if user_id == "-1":#未登录
            return HttpResponseRedirect("/login/")
        else:
            q_id = request.GET['questionid']
            q = Question.objects.get(id=q_id)
            if user_id == "-1":  # 0未关注 1关注
                status = 0
            else:
                follower = UserProfile.objects.get(user_id=user_id)#展示关注未关注图标
                followed = q.author
                if follower in followed.followed.all():
                    status = 1
                else:
                    status = 0
            objPost = ReplyForm(request.POST)#认证回复
            if objPost.is_valid():
                form_data = objPost.cleaned_data
                form_data['question'] = q
                form_data['nickname'] = User.objects.get(id=user_id).username
                form_data['user'] = UserProfile.objects.get(user=user_id)

                new_question_obj = Answer(**form_data)
                new_question_obj.save()
                print(q.author.user.id)
                if UserProfile.objects.get(user=user_id).user.id == q.author.user.id :#若是本人的回复不发通知
                    q = Question.objects.get(id=q_id)
                    list = Answer.objects.filter(question_id=q_id)
                    #print("if")
                else:#给问题的提问者发通知
                    #print("else")
                    q = Question.objects.get(id=q_id)
                    list = Answer.objects.filter(question_id=q_id)
                    psender = User.objects.get(id=user_id)
                    preceiver = q.author.user
                    notice = Notice(sender=psender,receiver=preceiver,type=0,q_id=q_id)
                    notice.content = psender.username + "回复了您的问题:"+q.title+"...请点击查看"
                    notice.save()
                objPost2 = ReplyForm()
                return render(request, "question.html", {'q': q,'list':list,'obj':objPost2,'userid':user_id,'status':status})
            else:
                objPost2 = ReplyForm()
                return render(request, 'question.html', {'obj': objPost2,'userid':user_id,'status':status})


@login_required
def getuserinfo_view(request):#展示基本信息
    if request.method == 'GET':
        user_id = request.GET['userid']
        user = User.objects.get(id=user_id)
        userprofile = UserProfile.objects.get(user_id=user_id)
        return render(request,"account.html",{'userbase':user,'userextend':userprofile})

def login_view(request):#登陆
    if request.method == 'GET':
        return render(request,"login.html")
    elif request.method == 'POST':
        email = request.POST['email']
        password = request.POST['password']
        user = authenticate(username=email,password=password)#用户认证
        if user is not None:
            login(request,user)
            user_id = user.id
            request.session.set_expiry(0)#关闭浏览器seesion就过期
            return HttpResponseRedirect("/home/?userid="+str(user_id))#显示主页
        else:
            return render(request,"login.html")

def logout_view(request):#退出登录
    logout(request)
    return HttpResponseRedirect("/login")

def signup_view(request):#注册
    if request.method == 'GET':
        return render(request,'register.html')
    elif request.method == 'POST':
        email = request.POST['email']
        username = request.POST['username']
        if User.objects.filter(email=email)or User.objects.filter(username=username):#邮箱唯一
            return render(request, "register.html")
        else:
            user = User()
            user.email = email
            user.username = request.POST['username']
            password = request.POST['password']
            user_profile = UserProfile()
            from django.contrib.auth.hashers import make_password
            user.password = make_password(password)#密码加密保存
            user.save()
            user_profile.user_id = user.id
            # 将注册未激活的信息保存到数据库
            user_profile.save()
            return HttpResponseRedirect("/login")

@login_required()
def newquestion_view(request):#发布问题
    from default.models import Question
    if request.method == 'POST':
        user_id = request.GET['userid']
        objPost = QusetionForm(request.POST)
        if objPost.is_valid():#对提交的问题做认证
            form_data = objPost.cleaned_data
            form_data['author'] = UserProfile.objects.get(user_id=user_id)
            form_data['authorname'] = User.objects.get(id=user_id).username

            new_question_obj = Question(**form_data)
            new_question_obj.save()
            #向关注对象发送消息提醒
            str1 = new_question_obj.authorname+"发布了新的问题:"+new_question_obj.title+"...请点击查看"
            userpro = UserProfile.objects.get(user_id = user_id)
            follower = userpro.myfollower.all()
            #print(follower)
            for item in follower:
                receiver = UserProfile.objects.get(user_id=item.user_id).user
                sender = UserProfile.objects.get(user_id=user_id).user
                notice = Notice(sender=sender,receiver=receiver,type=1,content=str1)
                notice.q_id=new_question_obj.id
                notice.save()


            return HttpResponseRedirect("/questionlist/?userid=" + str(user_id))
        else:
            print(objPost.errors)
            return render(request, 'questionlist.html', {'obj1': objPost})
            #return HttpResponseRedirect("/questionlist/?userid=" + str(user_id))
    else:
        #user_id = request.GET['userid']
        objGet = QusetionForm()
        return render(request,'newquestion.html',{'obj1':objGet})

@login_required()
def edituserinfo_view(request):#编辑个人信息
    if request.method == 'GET':
        user_id = request.GET['userid']
        user = User.objects.get(id=user_id)
        userprofile = UserProfile.objects.get(user_id=user_id)
        return render(request,"editAccount.html",{'userbase':user,'userextend':userprofile})
    else:
        user_id = request.GET['userid']
        user = UserProfile.objects.get(user_id=user_id)
        sex = request.POST['sex']
        edu = request.POST['edubackground']
        intro = request.POST['intro']
        user.sex = sex
        user.edubackground = edu
        user.intro = intro
        user.save()
        return HttpResponseRedirect("/userinfo/?userid=" + str(user_id))

@login_required()
def myfocus_view(request):#显示我的关注
    user_id = request.GET['userid']
    user = UserProfile.objects.get(user_id=user_id)
    focus = user.follower.all()
    return render(request,'focus.html',{'myfocus':focus,'userid':user_id})

@login_required()
def myfollower_view(request):#显示关注我的人
    user_id = request.GET['userid']
    user = UserProfile.objects.get(user_id=user_id)
    follow = user.followed.all()
    return  render(request,'follow.html',{'myfollow':follow,'userid':user_id})