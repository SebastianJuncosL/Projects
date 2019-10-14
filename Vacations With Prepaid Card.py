key = [123456, 678901, 135792, 246801]
adult_fare = []
kid_fare = []
password = ''
prepaid_card = 100
the_menu = {'pizza': 50, 'sopa': 30, 'agua': 10,
            'refresco': 15, 'helado': 25, 'pastel': 25}


def adult_menu():
    global adult_fare
    global the_menu
    print('-----MENU-----')
    for x in the_menu.keys():
        print(x)
    while True:
        food = input('What would you like to order?:\t')
        if food in the_menu:
            price = the_menu[food]
            adult_fare.append(price)
        option = input('Do you want to order something else for the adult?\n')
        if option == 'yes' or option == 'y':
            continue
        else:
            break


def kid_menu():
    global kid_fare
    global the_menu
    print('-----MENU-----')
    for x in the_menu.keys():
        print(x)
    while True:
        food = input('What would you like to order?:\t')
        if food in the_menu:
            if food == 'agua':
                price = the_menu[food]-5
            else:
                price = the_menu[food] - 10
            kid_fare.append(price)
        option = input('Do you want to order something else for the kid?\n')
        if option == 'yes' or option == 'y':
            continue
        else:
            break


def make_payment():
    global kid_fare
    global adult_fare
    global password
    global prepaid_card
    adult_total = 0
    kid_total = 0
    wifi = False
    for x in adult_fare:
        adult_total += x
    for x in kid_fare:
        kid_total += x
    print(f'You must pay: \nAdult: {adult_total}\nKid: {kid_total}\n')
    final_check = adult_total + kid_total
    print(f'Total:\t${final_check}')
    tip = input('Would you like to add a tip?:\t')
    if tip == 'y' or tip == 'yes':
        percentage = float(input('How much?\t'))
        if percentage >= .1:
            tipped = percentage * final_check
            total_with_tip = tipped + final_check
            only_the_tip = total_with_tip - final_check
            print('The total with tip is: ', total_with_tip)
            checking_password = int(
                input('Please enter your password to continue: '))
            if checking_password == password:
                if prepaid_card > total_with_tip:
                    discount_prepaid = input(
                        'Discount the tip from your card?\t')
                    if discount_prepaid == 'yes' or discount_prepaid == 'y':
                        payed = prepaid_card - total_with_tip
                        if payed > 500:
                            prepaid_card -= payed
                            print(
                                "Thank you for eating with us!\nWiFi's on the house!")
                            print(f'Your card now contains ${prepaid_card}')
                    else:
                        payed = prepaid_card - final_check
                        prepaid_card = payed
                        print('Thank you for eating with us!')
                else:
                    print(
                        'Insufficient funds in the prepaid card\nPlease recharge your prepaid card')

        else:
            print('The tip must be greater than 10%')
    else:
        checking_password = int(
            input('Please enter your password to continue: '))
        if checking_password == password:
            check_money = prepaid_card - final_check
            if check_money > 0:
                prepaid_card -= final_check
                print('Thank you for eating with us!')
                print(f'Your card now contains ${prepaid_card}')
            else:
                print(
                    'Insufficient funds in the prepaid card\nPlease recharge your prepaid card')


def card_recharge():
    global prepaid_card
    times_500 = 0
    while True:
        print('How much money do you wish to recharge?\na)\t$100\nb)\t$250\nc)\t$500')
        recharge = str(input())
        if recharge.lower() == 'a':
            prepaid_card += 100
        elif recharge.lower() == 'b':
            prepaid_card += 250
        elif recharge.lower() == 'c':
            prepaid_card += 500
            times_500 += 1
        else:
            print('Invalid letter\nTry Again Later')
        option = input('Do you want to recharge again?\n')
        if option == 'y' or option == 'yes':
            continue
        else:
            break
    if times_500 >= 3:
        prepaid_card += 100
        print("We'll give you $100 extra because of the amount you recharged!")
    print(f'Your actual balance is ${prepaid_card}')


def select_option():
    global kid_fare
    global adult_fare
    while True:
        print(
            '1.\tAdult Menu\n2.\tChild Menu\n3.\tMake payment\n4.\tCard recharge\n5.\tExit')
        option = int(input('What do you wish to do?\n'))
        if option == 1:
            adult_menu()
        elif option == 2:
            kid_menu()
        elif option == 3:
            make_payment()
        elif option == 4:
            card_recharge()
        elif option == 5:
            break
        else:
            print('\nPlease enter a valid number\n\n')


user = int(input('Please enter your acces key:\t'))
if user in key:
    password = user
    print('------WELCOME------\n')
    select_option()
else:
    print('Invalid key')
