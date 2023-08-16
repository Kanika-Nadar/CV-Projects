from django.forms import ModelForm
from .models import EmployeeModel, AdminModel

class AdminForm(ModelForm):
    class Meta:
        model=AdminModel
        fields=['username', 'password']
    
class EmployeeForm(ModelForm):
    class Meta:
        model=EmployeeModel
        fields=['name', 'age', 'hire_date', 'design', 'sal', 'contact', 'email', 'add']