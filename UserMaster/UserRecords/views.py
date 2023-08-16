from django.shortcuts import render, HttpResponse, HttpResponseRedirect
from .models import *
from .forms import EmployeeForm
# from django.template import Template, Context

def login(request):
    return render(request, 'login.html')

def adminvalidate(request):
    user_name=request.POST.get('user')
    pass_word=request.POST.get('passw')
    all_records=EmployeeModel.objects.all().values()
    all_designs = DesignationModel.objects.all().values()
    if (user_name=='kanika' and pass_word=='kanikapass'):
        return render(request, 'adminview.html', {'record':all_records, 'designs':all_designs})
    else:
        a='Login failed. Try again.'
        return render(request, 'admin_validate.html', {'success':a})
    
def register(request):
    designs=DesignationModel.objects.all().values()
    teles=TelephoneNosModel.objects.all().values()
    context={'designs':designs, 'teles':teles}
    return render(request, 'register.html', context)

def addEmployee(request):
    new_name=request.POST.get('fullname')
    new_age=request.POST.get('age')
    new_hire_date=request.POST.get('hiredate')
    chosen_design=request.POST.get('design')
    new_design=DesignationModel.objects.get(design=chosen_design) # the design object
    new_sal=request.POST.get('salary')
    new_contact=request.POST.get('contactno')
    ContactNosModel.objects.create(contact = new_contact) # creation of contact object
    contact_obj=ContactNosModel.objects.get(contact=new_contact) # the contact object
    new_email=request.POST.get('emailadd')
    new_add=request.POST.get('add')
    empmodel=EmployeeModel.objects.create(
        name=new_name,
        age=new_age,
        hire_date=new_hire_date,
        design=new_design,
        sal=new_sal,
        contact = contact_obj,
        email=new_email,
        add=new_add
    )
    new_tele=request.POST.getlist('telephone')
    for nt in new_tele:
        add_nt=TelephoneNosModel.objects.get(pk=nt)
        empmodel.teles.add(add_nt)
    empmodel.save()    
    return HttpResponseRedirect('http://127.0.0.1:8000/adminviewwithnewuser/')

def adminViewWithNewUser(request):
    all_records=EmployeeModel.objects.all()
    return render(request, 'adminview.html', {'record':all_records})

def updateEmployee(request, id):
    # getting old details
    update_emp=EmployeeModel.objects.get(pk=id)
    print(update_emp.contact.id)
    print(update_emp, type(update_emp))
    designs=DesignationModel.objects.all()
    contacts_obj=ContactNosModel.objects.get(id = update_emp.contact.id)
    telenos=TelephoneNosModel.objects.all()
    chosen_teles=update_emp.teles.all()
    # 1 model instance = 1 class (similar to a dict)
    # a QuerySet = an array of class (similar to a list of dicts)
    print(contacts_obj.contact, type(contacts_obj.contact), '\n')
    context={
        'emp':update_emp,
        'designs':designs,
        'contacts':contacts_obj,
        'telenos':telenos,
        'chosen_teles':chosen_teles
    }
    # print(update_emp.contact, type(update_emp.contact))
    # # print(contacts, type(contacts))
    # print('context', context['contacts'])
    return render(request, 'update.html', context)

def saveEmployee(request, id):
    # updating new details
    # u_name=request.POST.get('ufullname')
    # u_age=request.POST.get('uage')
    # u_hire_date=request.POST.get('uhiredate')
    # chosen_u_design=request.POST.get('udesign')
    # u_design=DesignationModel.objects.get(pk=chosen_u_design)
    # u_sal=request.POST.get('usalary')
    # u_email=request.POST.get('uemailadd')
    # u_add=request.POST.get('uadd')
    # updated_emp=EmployeeModel.objects.filter(pk=id).update(
    # name=u_name,
    # age=u_age,
    # hire_date=u_hire_date,
    # design=u_design,
    # sal=u_sal,
    # email=u_email,
    # add=u_add
    # )
    # updated_emp=EmployeeModel.objects.get(pk=id)
    # updated_emp.save()
    # chosen_contact=request.POST.get('ucontactno')
    # ContactNosModel.objects.create(contact = chosen_contact) # creation of contact object
    # u_contact=ContactNosModel.objects.filter(contact=chosen_contact) # the contact object
    # updated_emp.contact.set(u_contact)
    # u_tele=request.POST.getlist('telephone')
    # print('u_tele=',u_tele)
    # for ut in u_tele:
    #     add_ut=TelephoneNosModel.objects.get(tele=ut)
    #     print(ut)
    #     updated_emp.teles.add(add_ut)
    # print('add_ut=', add_ut)
    # updated_emp.save()

    updated_emp=EmployeeModel.objects.get(pk=id)
    updated_emp.teles.clear()
    updated_emp.contact.clear()
    u_name=request.POST.get('ufullname')
    u_age=request.POST.get('uage')
    u_hire_date=request.POST.get('uhiredate')
    chosen_u_design=request.POST.get('udesign')
    u_design=DesignationModel.objects.get(pk=chosen_u_design)
    u_sal=request.POST.get('usalary')
    u_contact = request.POST.get('ucontactno')
    u_email=request.POST.get('uemailadd')
    u_add=request.POST.get('uadd')
    updated_emp.name=u_name
    updated_emp.age=u_age
    updated_emp.hire_date=u_hire_date
    updated_emp.design=u_design
    updated_emp.sal=u_sal
    updated_emp.contact = u_contact
    updated_emp.email=u_email
    updated_emp.add=u_add
    updated_emp.save()
    # chosen_contact=request.POST.get('ucontactno')
    # ContactNosModel.objects.create(contact = chosen_contact) # creation of contact object
    # u_contact=ContactNosModel.objects.filter(contact=chosen_contact) # the contact object
    # for uc in u_contact:
    #     updated_emp.contact.add(uc)
    # updated_emp.contact.set(u_contact)
    u_tele=request.POST.getlist('utelephone')
    # n_tele=request.POST.getlist('telephone')
    
    for ut in u_tele:
        add_ut=TelephoneNosModel.objects.get(pk=ut)
        updated_emp.teles.add(add_ut)
    updated_emp.save()
    # for nt in n_tele:
    #     rem_nt=TelephoneNosModel.objects.filter(tele=nt).delete()
    
    # for nt in n_tele:
    #     rem_nt=TelephoneNosModel.objects.get(pk=nt)
    #     updated_emp=EmployeeModel.objects.get(pk=id)
    #     updated_emp.teles.remove(rem_nt)
    updated_emp.save()
    return HttpResponseRedirect('http://127.0.0.1:8000/adminviewwithnewuser/')

def deleteEmployee(request, id):
    delete_emp=EmployeeModel.objects.get(pk=id)
    delete_emp.delete()
    return HttpResponseRedirect('http://127.0.0.1:8000/adminviewwithnewuser/')

