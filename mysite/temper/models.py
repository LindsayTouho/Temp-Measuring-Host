# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models


class temper(models.Model):
    name = models.CharField(max_length=5)
    time = models.DateTimeField(auto_now_add=True)
    T1 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)
    T2 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)
    T3 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)
    T4 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)
    T5 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)
    T6 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)
    T7 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)
    T8 = models.DecimalField(decimal_places=1,max_digits=6,blank=True,null = True)

class users(models.Model):
    name = models.CharField(max_length=20)
    password = models.CharField(max_length=40)