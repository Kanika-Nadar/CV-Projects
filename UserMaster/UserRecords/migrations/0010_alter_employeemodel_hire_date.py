# Generated by Django 4.1 on 2023-05-17 10:28

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('UserRecords', '0009_alter_employeemodel_hire_date'),
    ]

    operations = [
        migrations.AlterField(
            model_name='employeemodel',
            name='hire_date',
            field=models.DateField(),
        ),
    ]
