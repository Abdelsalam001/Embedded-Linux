#include <iostream>
#include <string>
#include <vector>


class Employee
{
	private:

	std::string name;
	int age;
	int id;
	double salary;
	
	public:
/****************seters*****************************/		
	void set_name(std::string cp_name)
	{
		name=cp_name;
	}
	void set_salary(double cp_salary)
	{
		salary=cp_salary;
	}
	void set_age(int cp_age)
	{
		age=cp_age;
	}	void set_id(int cp_id)
	{
		id=cp_id;
	}
	
/****************geters*****************************/	
	
	std::string get_name()
	{
		return name;
	}
	double get_salary()
	{
		return salary;
	}
	int get_age()
	{
		return age;
	}
		int get_id()
	{
		return id;
	}
	
	void display()
    {
        std::cout << "Name => "<<get_name()<<std::endl;
        std::cout << "salary => "<<get_salary()<<std::endl;
        std::cout << "Age => "<<get_age()<<std::endl;
		std::cout << "id => "<<get_id()<<std::endl;
		std::cout <<"------------------------------"<<std::endl;
    }
};

class Company
{
    private:
        std::vector<Employee*> company;
    public:
        void Add_employee(Employee * employee)
        {
            company.push_back(employee);
        }
	
	void ubdate_employee_salary(std::string name, double salary)
	{
		bool flage =false;
		for(Employee* employee : company)
		{
			if(name==employee->get_name())
			{
				employee->set_salary(salary);
				flage = true;
				break;
			}
			if(!flage)
			{
				std::cout <<"------------------------------"<<std::endl;
				std::cout <<"no one has this name"<<std::endl;
				std::cout <<"------------------------------"<<std::endl;
			}
			
		}
	}
	
	void Delete_employee(std::string name)
	{
		
		bool flage =false;
		
		for(int i=0;i<company.size();i++)
		{
			if(name==company[i]->get_name())
			{
				company.erase(company.begin()+i);
				flage = true;
				break;
			}
			if(!flage)
			{
				std::cout <<"------------------------------"<<std::endl;
				std::cout <<"no one has this name"<<std::endl;
				std::cout <<"------------------------------"<<std::endl;
			}
			
		}
		
	}
	void show_allEmployee_data()
	{
		     for(auto employee : company)
            {
                employee->display();
            }
	}
	void show_employee_data(std::string name)
	{
		bool flage =false;
		for(Employee* employee : company)
		{
                if(name == employee->get_name())
                {
                    employee->display();
                    flage = true;
                    break;
                }
			if(!flage)
			{
				std::cout <<"------------------------------"<<std::endl;
				std::cout <<"no one has this name"<<std::endl;
				std::cout <<"------------------------------"<<std::endl;
			}
			
		}
	}
	
		void show_userEmployee_data(int id)
	{
		bool flage =false;
		for(Employee* employee : company)
		{
                if(id == employee->get_id())
                {
                    employee->display();
                    flage = true;
                    break;
                }
			if(!flage)
			{
				std::cout <<"------------------------------"<<std::endl;
				std::cout <<"no one has this id"<<std::endl;
				std::cout <<"------------------------------"<<std::endl;
			}
			
		}
	}
	
	
	
};



int main()
{
int choice;
long int pass=112233;
long int pass_user;
std::string mood;
std::string name_1;
double salary_1;
int age_1;
int id_1;
Company company_obj;

while(true)
 {		
       std::cout<<"please enter the mood(eployee_mood/Hr_mood)"<<std::endl;
	   std::cin>>mood;
		
		if(mood=="employee_mood")
		{
			bool flage_scoop_1=true;
			while(flage_scoop_1)
			{
				std::cout<<"you can only show your data with id..........please enter your id"<<std::endl;
				std::cout<<"for exit mood press :1"<<std::endl;
				std::cin>>id_1;
				if(id_1==1)
				{
					flage_scoop_1=false;
				}
				company_obj.show_userEmployee_data(id_1);
			}
		}
		else if(mood=="Hr_mood")
		{	
			std::cout<<"please enter Hr mood password"<<std::endl;
			std::cin>>pass_user;
			if(pass_user==pass)
			
			{	
				std::cout<<"it's a correct password........You access Hr_mood Successfully"<<std::endl;
				std::cout<<"please enter the process you want"<<std::endl;
				bool flage_scoop_2=true;
			    while(flage_scoop_2)
				{
					std::cout<<"----------------------------------------"<<std::endl;
					std::cout<<"for add employee enter               : 1"<<std::endl;
					std::cout<<"for update salary to employee enter  : 2"<<std::endl;
					std::cout<<"for delete employee data enter       : 3"<<std::endl;
					std::cout<<"for show employee data enter         : 4"<<std::endl;
					std::cout<<"for show all employees data enter    : 5"<<std::endl;
					std::cout<<"for exit Hr_mood enter               : 6"<<std::endl;
					std::cout<<"----------------------------------------"<<std::endl;
					std::cin>>choice;
		
					if(choice==1)
					{
						std::cout<<"please enter employee name"<<std::endl;
						std::cin>>name_1;
						std::cout<<"please enter employee salary"<<std::endl;
						std::cin>>salary_1;
						std::cout<<"please enter employee age"<<std::endl;
						std::cin>>age_1;
						std::cout<<"please enter employee id"<<std::endl;
						std::cin>>id_1;
						
				
							Employee *employee = new Employee();
							employee->set_name(name_1);
							employee->set_age(age_1);
							employee->set_salary(salary_1);
							employee->set_id(id_1);
				
							company_obj.Add_employee(employee);
							//delete employee;
					}
					
					else if(choice==2)
					{
						std::cout<<"please enter employee name"<<std::endl;
						std::cin>>name_1;
						std::cout<<"please enter employee new salary"<<std::endl;
						std::cin>>salary_1;
						company_obj.ubdate_employee_salary(name_1,salary_1);
					}
					else if(choice==3)
					{
						std::cout<<"please enter employee name"<<std::endl;
						std::cin>>name_1;
						company_obj.Delete_employee(name_1);
					}
					else if(choice==4)
					{
						std::cout<<"please enter employee name"<<std::endl;
						std::cin>>name_1;
						company_obj.show_employee_data(name_1);
						
					}
					else if(choice==5)
					{
						company_obj.show_allEmployee_data();
					}
					else if(choice==6)
						{
							flage_scoop_2=false;
						}
					
					else{std::cout<<"there is no process with this number >_<....please try again"<<std::endl;}
				}
			}
		}
		
	
	
	
  }
	return 0;
	
}





