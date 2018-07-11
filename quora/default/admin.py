from django.contrib import admin
from django.contrib.auth.models import User
from default.models import UserProfile
from  default.models import Question
from default.models import Answer


# Register your models here.
class ProfileInline(admin.StackedInline):
    model = UserProfile
    verbose_name = 'profile'

class UserProfileAdmin(admin.ModelAdmin):
    inlines = (ProfileInline,)
    fields = ('username','email','password')
    '''
    fieldsets = (
        ['Main',{
            'fields':('username','email','password')
        }],
        
        ['Advance',{
            'classes':('collapse',),#CSS
            'fields':('sex','edubackground','intro'),
        }]
       
    )
 '''
admin.site.unregister(User)
admin.site.register(User,UserProfileAdmin)
admin.site.register(Question)
admin.site.register(Answer)