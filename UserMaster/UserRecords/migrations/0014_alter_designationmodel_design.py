# Generated by Django 4.1 on 2023-05-18 06:53

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('UserRecords', '0013_alter_employeemodel_design'),
    ]

    operations = [
        migrations.AlterField(
            model_name='designationmodel',
            name='design',
            field=models.CharField(blank=True, max_length=50, null=True),
        ),
    ]
