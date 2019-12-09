



def calc_fuel_from_mass(mass):
    return (mass//3) - 2


def calc_fuel(mass_of_fuel):
    print('mass =' + str(mass_of_fuel))
    total = 0
    val = calc_fuel_from_mass(mass_of_fuel)
    print(val)
    if val < 0:
        return 0
    else:
        val + calc_fuel(val)




def calc_loop(mass_of_fuel):
    running_total = 0
    calc = mass_of_fuel
    while(calc >= 0):
        calc = calc_fuel_from_mass(calc)
        if calc > 0:
            running_total += calc

    return running_total        



def test():
    x = 100756
    modulefuel = calc_fuel_from_mass(x)
    print(modulefuel)
    fuel_for_fuel =  calc_loop(modulefuel)
    print (fuel_for_fuel)
    print(fuel_for_fuel + modulefuel)



if __name__ == "__main__":
#    test()
    
    inputFile = open('day_1_input.txt')
    lines = inputFile.readlines()
    total = 0
    for l in lines:
        modulefuel = calc_fuel_from_mass(int(l))
        fuel_mass = calc_loop(modulefuel)
        val = modulefuel + fuel_mass
        total += val
    

    

    print(total)
