from django.db import models
from django.contrib.auth.models import User
from django.contrib.contenttypes.models import ContentType
from django.contrib.contenttypes import fields
from quora import settings
from django.db.models import signals
# Create your models here.class

class UserProfile(models.Model):
    #扩展User
    user = models.OneToOneField(User)
    follower = models.ManyToManyField('self',blank=True,null=True,related_name='myfollower',symmetrical=False)#不对称，不是互关关系
    followed = models.ManyToManyField('self', blank=True, null=True, related_name='myfollowed',symmetrical=False)  # 不对称，不是互关关系
    followedcount = models.IntegerField(default=0) #关注人数
    sex = models.CharField(max_length = 3, default = "未知") #0男 1女 3未知
    edubackground = models.CharField(max_length = 10,blank = True)
    intro = models.CharField(max_length = 100,default = "这个人很懒")

    def checkfriend(self,user):
        if user in self.follower.all():
            return True
        else:
            return False

class Question(models.Model):
    title = models.CharField(u'问题标题',max_length=255,unique=True)
    '''
    head_img = models.ImageField(upload_to="uploads")
    '''
    content = models.CharField(u"内容",max_length=1000)
    author = models.ForeignKey("UserProfile")
    publish_date = models.DateTimeField(auto_now_add = True)
    authorname = models.CharField(max_length=20,blank=True)
    viewscount = models.IntegerField(default=0)

    class Meta:
        ordering = ['-publish_date']

    def __str__(self):
        return self.title

class Answer(models.Model):
    #回答表
    question = models.ForeignKey("Question")
    #回答用户
    user = models.ForeignKey("UserProfile")
    #回答内容
    answer = models.TextField(max_length = 1000)
    #评论时间
    date = models.DateTimeField(auto_now = True)
    #回答者昵称
    nickname = models.CharField(max_length=20,blank=True)

    def __str__(self):
        return self.answer
    def description(self):
        return u'%s回答了您的问题：%s...请点击查看' %(self.nickname,self.question.title)


'''
class Message(models.Model):
    sender = models.ForeignKey(settings.AUTH)


class Event(models.Model):
    user = models.ForeignKey(User)
    content_type = models.ForeignKey(ContentType)
    object_id = models.PositiveIntegerField()

    content_object = fields.GenericForeignKey('content_type','object_id')
    created = models.DateTimeField(u'事件发生时间',auto_now_add=True)

    def __str__(self):
        return "%s的事件:%s" %(self.user,self.description())

    def description(self):
        return self.content_object.description()
'''
class Notice(models.Model):
    sender = models.ForeignKey(User,related_name='notice_sender')
    receiver = models.ForeignKey(User,related_name='notice_receiver')
    content = models.CharField(max_length=100,blank=True)
    status = models.BooleanField(default=False) #是否阅读
    type = models.IntegerField() #通知类型
    created_at = models.DateTimeField(auto_now_add=True)
    updated_at = models.DateTimeField(auto_now=True)
    q_id = models.CharField(max_length= 1000,blank=True)
    class Meta:
        db_table = 'notice'
        ordering = ['-created_at']
        verbose_name_plural = u'通知'
   
    def  __unicode__(self):
        return u"%s的事件：%s"%(self.sender,self.description())
    
    def reading(self):
        if not self.status:
            self.status = True
    def description(self):
        if self.event:
            return self.event.description()
        return "No Event"
'''
def reply_save(sender,instance,signal,*args,**kwargs):
    entity = instance
    if entity.author != entity.post.author:
        event = Notice(sender=entity.author,receiver=entity.post.author,event=entity,type=0)
        event.save()
'''
'''
def newreply_save(sender,instance,signal,*args,**kwargs):
    #sender监测Answer类
    #instance监测Answer类
    #signal信号类
    entity = instance
    if entity.user_id != entity.question.author_id:
        print(entity.user.user)
        print(entity.question.author)
        event = Notice(sender=entity.user.user,receiver=entity.question.author,event=entity,type=0)
        event.save()

signals.post_save.connect(newreply_save,sender=Answer)
'''