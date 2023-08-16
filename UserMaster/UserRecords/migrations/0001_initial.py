# Generated by Django 4.1 on 2023-05-16 04:34

from django.db import migrations, models


class Migration(migrations.Migration):

    initial = True

    dependencies = [
    ]

    operations = [
        migrations.CreateModel(
            name='UserRecordsModel',
            fields=[
                ('id', models.AutoField(editable=False, primary_key=True, serialize=False)),
                ('fname', models.CharField(max_length=50)),
                ('lname', models.CharField(max_length=50)),
                ('age', models.IntegerField()),
                ('hire_date', models.DateTimeField()),
                ('design', models.CharField(max_length=50)),
                ('sal', models.IntegerField(default=0)),
                ('contact', models.CharField(max_length=10)),
                ('email', models.EmailField(max_length=254)),
            ],
        ),
    ]