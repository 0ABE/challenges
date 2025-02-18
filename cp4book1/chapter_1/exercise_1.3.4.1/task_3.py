#  
#  .d8888b.        d8888 888888b.   8888888888
# d88P  Y88b      d88888 888  "88b  888
# 888    888     d88P888 888  .88P  888
# 888    888    d88P 888 8888888K.  8888888
# 888    888   d88P  888 888  "Y88b 888
# 888    888  d88P   888 888    888 888
# Y88b  d88P d8888888888 888   d88P 888
#  "Y8888P" d88P     888 8888888P"  8888888888
# 
# Copyright (c) 2025, Abe Mishler
# Licensed under the Universal Permissive License v 1.0
# as shown at https://oss.oracle.com/licenses/upl/.
# 

from datetime import date

#Get today's date.
today = date.today()

#Get the date in the past from user input.
args = [int(x) for x in input("Month Day Year: ").split()]
# Convert user input to a date object.
past_date = date(args[2], args[0], args[1]) # y, m, d

#Results : day of the week and days elapsed to present.
print(past_date.strftime("%a"))
print("{} day(s) ago".format((today - past_date).days))

