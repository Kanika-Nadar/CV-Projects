# Generated by Django 4.1 on 2023-05-16 05:30

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('UserRecords', '0003_adminrecordsmodel'),
    ]

    operations = [
        migrations.AlterField(
            model_name='userrecordsmodel',
            name='hire_date',
            field=models.DateField(),
        ),
    ]
