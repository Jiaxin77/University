from django.conf.urls import url

from . import views

urlpatterns = [
    url(r'^userinfo/$',views.getuserinfo_view),
    url(r'^login/$',views.login_view),
    url(r'^signup/$',views.signup_view),
    url(r'^logout/$',views.logout_view),
    url(r'^edituserinfo/$',views.edituserinfo_view),
    url(r'^questionlist/$',views.getquestionlist_view),
    url(r'^postquestion/$',views.newquestion_view),
    url(r'^questiondetail/$',views.questiondetail_view),
    url(r'^home/$',views.home_view),
    url(r'^noticelist/$',views.getnoticelist_view),
    url(r'^follow/$',views.follow_view),
    url(r'^myfocus/$',views.myfocus_view),
    url(r'^myfollower/$',views.myfollower_view),
    url(r'^delete/$',views.delete_view),
]