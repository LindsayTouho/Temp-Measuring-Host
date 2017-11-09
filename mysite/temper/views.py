# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from .models import users,temper

from django.shortcuts import render
from hashlib import md5
from django.http.response import HttpResponse
from django.core.paginator import Paginator
from .forms import searcher
from math import ceil

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
    S=searcher(request.GET)
    endDate=''
    startDate=''
    upTemper =''
    ID= ''
    if S.is_valid():
        cd = S.cleaned_data
        startDate = cd['startDate']
        endDate = cd['endDate']


        result = temper.objects.filter(time__lt= endDate).filter(time__gt=startDate)


        if cd['ID']:
            ID = cd['ID']
            result = result.filter(name=ID)
        if cd['upTemper']:
            upTemper=int(cd['upTemper'])
        return render(request, 'search.html', locals())
    return HttpResponse("Fail")

def page(request,page_num):
    page_num = int(page_num)
    S=searcher(request.GET)
    upTemper =''
    ID= ''
    if S.is_valid():
        cd = S.cleaned_data
        startDate = cd['startDate']
        endDate = cd['endDate']


        result = temper.objects.filter(time__lt= endDate).filter(time__gt=startDate)



        if cd['ID']:
            ID = cd['ID']
            result = result.filter(name=ID)
        if cd['upTemper']:
            upTemper=int(cd['upTemper'])

        l = request.get_full_path()[:13]
        links = []
        i = 1
        while i <= ceil(result.count()/100)+1:
            links.append(l + str(i) + '?startDate=' + str(startDate) + '&endDate=' + str(endDate) + '&ID=' + str(ID)+'&upTemper='+str(upTemper))
            i += 1

        result = result[(page_num - 1) * 100:page_num * 100]


        return render(request, 'search_page.html', locals())
    return HttpResponse("Fail")