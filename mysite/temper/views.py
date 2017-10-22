# -*- coding: utf-8 -*-
from __future__ import unicode_literals
from .models import users

from django.shortcuts import render
from hashlib import md5

def index(request):
    return render(request,'')

def login(request):
    username = request.POST[0]
    password = request.POST[1]
    if users.objects.get(name=username,password=md5(password)):
        return