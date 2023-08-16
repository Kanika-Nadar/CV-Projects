from django.db import models

# Foreign key tables
class DesignationModel(models.Model):
    id=models.CharField(max_length=10, primary_key=True)
    design=models.CharField(max_length=50, blank=True, null=True)
    def __str__(self):
        return self.design

class ContactNosModel(models.Model):
    contact=models.CharField(max_length=11)
    def __str__(self):
        return self.contact
    
class TelephoneNosModel(models.Model):
    tele=models.CharField(max_length=5, blank=True, null=True)
    def __str__(self):
        return self.tele

class EmployeeModel(models.Model):
    id=models.AutoField(primary_key=True, editable=False)
    name=models.CharField(max_length=100, blank=True, null=True)
    age=models.CharField(blank=True, null=True, max_length=3)
    hire_date=models.DateField()
    design=models.ForeignKey(DesignationModel, on_delete=models.PROTECT)
    sal=models.IntegerField(default=0)
    contact=models.ForeignKey(ContactNosModel, on_delete=models.PROTECT, blank=True, null=True)
    email=models.EmailField(blank=True, null=True)
    teles=models.ManyToManyField(TelephoneNosModel, related_name='employees', blank=True)
    add=models.TextField(blank=True, null=True)

    # def employeeContactNos(self):
    #     return ", ".join([str(c) for c in self.contact.all()])
    
    def employeeTeleNos(self):
        return ", ".join([str(t) for t in self.teles.all()])

class AdminModel(models.Model):
    username=models.CharField(max_length=20)
    password=models.CharField(max_length=100)
