# Generated by Django 4.1 on 2023-05-20 16:24

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('UserRecords', '0020_remove_employeemodel_tele_and_more'),
    ]

    operations = [
        migrations.AlterField(
            model_name='employeemodel',
            name='teles',
            field=models.ManyToManyField(blank=True, null=True, related_name='employees', to='UserRecords.telephonenosmodel'),
        ),
    ]
