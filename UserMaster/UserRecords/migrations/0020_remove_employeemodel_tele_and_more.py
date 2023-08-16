# Generated by Django 4.1 on 2023-05-20 15:17

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('UserRecords', '0019_employeemodel_tele'),
    ]

    operations = [
        migrations.RemoveField(
            model_name='employeemodel',
            name='tele',
        ),
        migrations.RemoveField(
            model_name='telephonenosmodel',
            name='teleno',
        ),
        migrations.AddField(
            model_name='employeemodel',
            name='teles',
            field=models.ManyToManyField(related_name='employees', to='UserRecords.telephonenosmodel'),
        ),
        migrations.AddField(
            model_name='telephonenosmodel',
            name='tele',
            field=models.CharField(blank=True, max_length=5, null=True),
        ),
    ]
