# Generated by Django 4.1 on 2023-05-17 08:14

from django.db import migrations


class Migration(migrations.Migration):

    dependencies = [
        ('UserRecords', '0006_alter_userrecordsmodel_contact'),
    ]

    operations = [
        migrations.RenameModel(
            old_name='AdminRecordsModel',
            new_name='AdminModel',
        ),
        migrations.RenameModel(
            old_name='UserRecordsModel',
            new_name='EmployeeModel',
        ),
    ]
