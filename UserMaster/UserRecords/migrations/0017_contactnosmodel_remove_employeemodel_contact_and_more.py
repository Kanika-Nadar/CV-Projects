# Generated by Django 4.1 on 2023-05-19 05:58

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('UserRecords', '0016_alter_designationmodel_id'),
    ]

    operations = [
        migrations.CreateModel(
            name='ContactNosModel',
            fields=[
                ('id', models.BigAutoField(auto_created=True, primary_key=True, serialize=False, verbose_name='ID')),
                ('contact', models.CharField(max_length=11)),
            ],
        ),
        migrations.RemoveField(
            model_name='employeemodel',
            name='contact',
        ),
        migrations.AddField(
            model_name='employeemodel',
            name='contact',
            field=models.ManyToManyField(to='UserRecords.contactnosmodel'),
        ),
    ]