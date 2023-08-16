from django.urls import path
from . import views

urlpatterns = [
    path('login/', views.login, name='login'),
    path('adminvalidate/', views.adminvalidate, name='adminvalidate'),
    path('register/', views.register, name='register'),
    path('addemployee/', views.addEmployee, name='addemployee'),
    path('adminviewwithnewuser/', views.adminViewWithNewUser, name='adminviewwithnewuser'),
    path('update/<id>/', views.updateEmployee, name='update'),
    path('delete/<id>/', views.deleteEmployee, name='delete'),
    path('saveemployee/<id>/', views.saveEmployee, name='saveemployee')
]
