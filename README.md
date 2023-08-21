# Car-Rental-System

This project covers the car rental system design, in particularly, car ordering system. The general poperties of this design are listed as follows:

1) It gets ustomer's start and end dates as input in the format mm/dd/yyyy.
2) If the dates are not entered correctly (start date before today's date, end date before start date, or dates do not follow the requested fromat),
the code will ask teh customer to enter valid dates.
3) The program will list the cars that are available for those specific dates (e.g., the program only lists the cars in the inventory which are available for
the requested dates and will not list the ones that are reserved for some/all days of the new customer's request).
4) After the customer enters its desired vehicle from the list, the program receives customer name as input, and generates an invoice for the reservation
and the estimated rental cost.

To store car information, a structure named "car" is defined. For managing car rental's vehicles, and getting orders from customers, the Car_Rental class 
is defined. The "add_car" method is used to enter the information of a new car into the system. The method "customer_request" is used to get an order from the customer. 
Below you can see an example of the code execution.

![Screenshot 2023-08-21 at 12 35 13 PM](https://github.com/sahandmsh/Car-Rental-System/assets/82970651/e0a0b2a2-63d2-4302-8db2-c869b632da33)

![Screenshot 2023-08-21 at 12 37 50 PM](https://github.com/sahandmsh/Car-Rental-System/assets/82970651/f9ba5a80-39f3-4e58-bc18-ae8d712c533e)

![Screenshot 2023-08-21 at 12 40 34 PM](https://github.com/sahandmsh/Car-Rental-System/assets/82970651/62acc417-53f3-442a-8e75-2de13ed7aff3)

