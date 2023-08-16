from django.contrib import admin
from .models import EmployeeModel, DesignationModel, ContactNosModel, TelephoneNosModel

class EmployeeModelView(admin.ModelAdmin):
    list_display=('id', 'name', 'age', 'hire_date', 'design', 'sal', 'contact', 'email', 'employeeTeleNos', 'add')
admin.site.register(EmployeeModel, EmployeeModelView)

class ContactNosModelView(admin.ModelAdmin):
    list_display=('id','contact')
admin.site.register(ContactNosModel, ContactNosModelView)

class DesignationModelView(admin.ModelAdmin):
    list_display=('id', 'design')
admin.site.register(DesignationModel, DesignationModelView)

class TelephoneNosModelView(admin.ModelAdmin):
    list_display=('id', 'tele')
admin.site.register(TelephoneNosModel, TelephoneNosModelView)
