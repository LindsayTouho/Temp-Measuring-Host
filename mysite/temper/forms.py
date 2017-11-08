from django import forms

class searcher(forms.Form):
    startDate = forms.DateField()
    endDate = forms.DateField()
    upTemper = forms.CharField(required=False)
    ID = forms.CharField(required=False)