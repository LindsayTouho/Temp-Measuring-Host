# -*- coding: utf-8 -*-
from __future__ import unicode_literals

from django.contrib import admin

from . import models

# Register your models here.

class temperAdmin(admin.ModelAdmin):
    list_display = ('time', 'name')

admin.site.register(models.temper,temperAdmin)
admin.site.register(models.users)