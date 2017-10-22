# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.db import models


class temper(models.Model):
    name = models.CharField(max_length=5,)
    T1 = models.DecimalField(decimal_places=2,max_digits=6,null=True)
    T2 = models.DecimalField(decimal_places=2,max_digits=6,null=True)
    T3 = models.DecimalField(decimal_places=2,max_digits=6,null=True)
    T4 = models.DecimalField(decimal_places=2,max_digits=6,null=True)
    T5 = models.DecimalField(decimal_places=2,max_digits=6,null=True)
    T6 = models.DecimalField(decimal_places=2,max_digits=6,null=True)
    T7 = models.DecimalField(decimal_places=2,max_digits=6,null=True)
    T8 = models.DecimalField(decimal_places=2,max_digits=6,null=True)