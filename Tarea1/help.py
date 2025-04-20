import re

password = "1234567890"
rules = {"prime":["1","2","3","5","7"],"even":["0","2","4","6","8"],"odd":["1","3","5","7","9"]}
def broken_rules(password, rules, min_length):
 
    broken_rules = []
    if(len(password) < min_length):
        broken_rules.append("MINIMUM_SIZE")
        
    for rule in rules:
        rule_regex = "[^"
        for char in rules[rule]:
            rule_regex += char
        rule_regex += "]"
        print(rule_regex)
    return broken_rules

print(broken_rules(password, rules, 8)