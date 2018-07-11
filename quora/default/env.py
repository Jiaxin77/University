from django import forms

class QusetionForm(forms.Form):
    title = forms.CharField(max_length=255,min_length=5,widget=forms.TextInput(attrs={'size':40 , 'class':'form-control title'}))
    content = forms.CharField(max_length=1000,widget=forms.Textarea(attrs={'rows': 8 ,'cols':30,  'class':'form-control content'}))


class ReplyForm(forms.Form):
    answer = forms.CharField(max_length=500,widget=forms.Textarea(attrs={'cols':30, 'rows': 8, 'class':'form-control reply', 'placeholder':'请输入您的回复'}))
