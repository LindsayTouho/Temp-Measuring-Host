# -*- coding: utf-8 -*-
# Generated by Django 1.11.2 on 2017-10-22 02:43
from __future__ import unicode_literals

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('temper', '0002_auto_20171022_0237'),
    ]

    operations = [
        migrations.RenameModel(
            old_name='temp',
            new_name='temper',
        ),
    ]
