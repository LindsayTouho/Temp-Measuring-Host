# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from .models import users,temper

from django.shortcuts import render
from hashlib import md5
from django.http.response import HttpResponse
import datetime

def index(request):
    return render(request,'index.html')

def login(request):
    if 'userName' in request.POST and request.POST['userName']:
        username = request.POST['userName']
    else :
        username = ' '
    if 'passWord' in request.POST and request.POST['passWord']:
        passWord = md5(request.POST['passWord'])
    else :
        passWord = '\\'
    try:
        if users.objects.get(name=username) and (users.objects.get(name=username).password== passWord.hexdigest()):
            return render(request,'login.html')
        else :
            return  HttpResponse("Invaild user name or password")
    except:
        return HttpResponse("Invaild user name or password")

def search(request):
    startDate = request.POST['startDate']
    endDate = request.POST['endDate']
    if 'upTemper' in request.POST and request.POST['upTemper']:
        upTemper = request.POST['upTemper']
    else:
        upTemper = '99'
    result = temper.objects.filter(time__lt= datetime.datetime.strptime(endDate,"%Y-%m-%d") ).filter(time__gt=datetime.datetime.strptime(startDate,"%Y-%m-%d"))
    if 'ID' in request.POST and request.POST['ID']:
        ID = request.POST['ID']
        result = result.filter(name=ID)
    return render(request,'search.html',{'chart':result.values(),'upTemper':int(upTemper)})
