## -*- coding: utf-8 -*- tab-width: 4 spaces -*-
#
# @file: tarea.py
# @brief: This script processes a log file to manage user passwords and rules acording to specific commands.
# @date: 01/04/2025
# @author: Katherine Huidobro

# Imports
import re




def is_only_digits(text):
    """ <h1>is_only_digits(text)</h1>     
    @brief Detecta si el texto contiene solo dígitos por medio de una expresión regular ***"\d+"***.
    
    @param text:   ***(string) Texto de entrada a revisar.***
    @return: - (bool) True si el texto contiene solo dígitos, False en caso contrario.
    
    """
    detect_digits = re.compile(r'\d+')
    return bool(detect_digits.fullmatch(text))

def get_character_list(text):
    """ <h1>get_character_list(string)</h1>     
    @brief Genera una lista de caracteres a partir de una cadena de texto usando el regex ***"[a-zA-Z0-9]"***.
    
    @param text:   ***(string) Texto de entrada a revisar.***
    @return: - (set) Conjunto de caracteres únicos presentes en la cadena de texto.
    
    """
    detext_characters = re.compile(r'[a-zA-Z0-9]')
    return detext_characters.findall(text)



def process_log(file_path_input, file_path_output):
    """ <h1>process_log(file_path_input, file_path_output)</h1>
    @brief Procesa un archivo de log para gestionar contraseñas de usuarios y reglas según comandos específicos.
    @param file_path_input:   ***(string) Ruta del archivo de entrada.***
    @param file_path_output:  ***(string) Ruta del archivo de salida.***
    @return: - (None) No retorna nada.
    
    """
    rules = {}
    min_length = 0
    command_pattern = re.compile(r'(\w+)| ([a-zA-Z0-9,]+)')
    claves = {}
    with open(file_path_input, 'r') as ifile:
        with open(file_path_output, 'w') as ofile:
            for line in ifile:                
                args_cardinality = len(command_pattern.findall(line))
                match args_cardinality:
                    case 3:                   
                        match (command_pattern.findall(line)[0][0], command_pattern.findall(line)[1][1]):
                            case ("SIZE", "RULE"):
                                if(is_only_digits(command_pattern.findall(line)[2][1])):
                                    min_length = int(command_pattern.findall(line)[2][1])
                                    ofile.write(f"✓ Regla de tamaño minimo actualizada exitosamente a {min_length}.\n")
                                else:
                                    ofile.write(f"✗ ERROR: Argumeto invalido como tamaño para regla en comando: {line}. Se esperaba un número entero positivo, y se entrego \"{command_pattern.findall(line)[2][1]}\"\n")
                            case ('DELETE', 'RULE'):
                                if command_pattern.findall(line)[2][1] in rules:
                                    del rules[command_pattern.findall(line)[2][1]]
                                    ofile.write(f"✓ Regla {command_pattern.findall(line)[2][1]} eliminada\n")
                                else:
                                    ofile.write(f"✗ ERROR:  Regla {command_pattern.findall(line)[2][1]} no existe\n")
                    case 4:
                        match (command_pattern.findall(line)[0][0], command_pattern.findall(line)[1][1]):
                            case ("SHOW", "PASSWORD"):
                                if(command_pattern.findall(line)[2][1] == "FROM"):
                                    if(command_pattern.findall(line)[3][1] in claves):
                                        ofile.write(f"✓ Contraseña del usuario {command_pattern.findall(line)[3][1]} es: {claves[command_pattern.findall(line)[3][1]]}\n")
                                    else:
                                        ofile.write(f"✗ ERROR: Usuario {command_pattern.findall(line)[3][1]} no registrado.\n")
                                else:
                                    ofile.write(f"✗ ERROR: argumento \"{command_pattern.findall(line)[2][1]}\" no registrado para comando SHOW PASSWORD\n")
                            case ('NEW','RULE'):
                                if command_pattern.findall(line)[2][1] not in rules:
                                    rules[command_pattern.findall(line)[2][1]] = get_character_list(command_pattern.findall(line)[3][1])
                                    ofile.write(f"✓ Regla {command_pattern.findall(line)[2][1]} creada exitosamente con restricciones {command_pattern.findall(line)[3][1]}\n")
                                else:
                                    ofile.write(f"✗ ERROR: Regla de nombre {command_pattern.findall(line)[2]} ya esta registrada.\n")
                            case ('ADD_TO', 'RULE'):
                                if command_pattern.findall(line)[2][1] in rules:
                                    additional_restrictions = get_character_list(command_pattern.findall(line)[3][1])
                                    for restriction in get_character_list(command_pattern.findall(line)[3][1]):
                                        if restriction not in rules[command_pattern.findall(line)[2][1]]:
                                            rules[command_pattern.findall(line)[2][1]].append(restriction)
                                    ofile.write(f"✓ Restricciones {additional_restrictions} añadidas a la regla {command_pattern.findall(line)[2][1]}\n")
                                else:
                                    ofile.write(f"✗ ERROR: Regla {command_pattern.findall(line)[2][1]} no registrada.\n")
                                    
                            case ('REMOVE_FROM', 'RULE'):
                                if command_pattern.findall(line)[2][1] in rules:
                                    additional_restrictions = get_character_list(command_pattern.findall(line)[3][1])
                                    for restriction in get_character_list(command_pattern.findall(line)[3][1]):
                                        if restriction in rules[command_pattern.findall(line)[2][1]]:
                                            rules[command_pattern.findall(line)[2][1]].remove(restriction)
                                    ofile.write(f"✓ Restricciones {additional_restrictions} eliminadas de la regla {command_pattern.findall(line)[2][1]}\n")
                                else:
                                    ofile.write(f"✗ ERROR: Regla {command_pattern.findall(line)[2][1]} no registrada.\n")
                                    
                            case ('DELETE', 'PASSWORD'):
                                if command_pattern.findall(line)[2][1] == "FROM":
                                    if command_pattern.findall(line)[3][1] in claves:
                                        del claves[command_pattern.findall(line)[3][1]]
                                        ofile.write(f"✓ Contraseña eliminada del usuario {command_pattern.findall(line)[3][1]}\n")
                                    else:
                                        ofile.write(f"✗ ERROR: Usuario {command_pattern.findall(line)[3][1]} no registrado.\n")
                                else:
                                    ofile.write(f"✗ ERROR: argumento \"{command_pattern.findall(line)[2][1]}\" no registrado para comando DELETE PASSWORD\n")
                    case 5:
                        match command_pattern.findall(line)[0][0]:
                            case 'NEW':
                                user = command_pattern.findall(line)[2][1]
                                password = command_pattern.findall(line)[3][1]
                                if command_pattern.findall(line)[2][1] == "FROM" and command_pattern.findall(line)[1][1] == "PASSWORD":
                                    if user not in claves:
                                        password = command_pattern.findall(line)[4][1]
                                        if broken_rules(password, rules, min_length):
                                            ofile.write(f"✗ ERROR: Contraseña {password} no valida para el usuario {command_pattern.findall(line)[3][1]} debido a que no cumple con las reglas {broken_rules(password, rules, min_length)}\n")
                                        else:
                                            claves[command_pattern.findall(line)[3][1]] = password
                                            ofile.write(f"✓ Contraseña {password} registrada exitosamente para el usuario {command_pattern.findall(line)[3][1]} \n")
                                    else:
                                        ofile.write(f"✗ ERROR: Usuario {command_pattern.findall(line)[3]} ya registrado.\n")
                                else:
                                    ofile.write(f"✗ ERROR: argumento \"{command_pattern.findall(line)[2]}\" invalido, usuario no registrado por comando NEW PASSWORD\n")
                            case 'FUSION':
                                if(command_pattern.findall(line)[3][1] == 'INTO' ):
                                    user1 = command_pattern.findall(line)[1][1]
                                    user2 = command_pattern.findall(line)[2][1]
                                    user3 = command_pattern.findall(line)[4][1]
                                    if user1 in claves and user2 in claves:
                                        temp_clave3 = claves[user1] + claves[user2]
                                        claves[user3] = claves[user1] + claves[user2]
                                        if(broken_rules(temp_clave3, rules, min_length)):
                                            ofile.write(f"✗ ERROR: Contraseña {temp_clave3} no valida para el usuario {user3} debido a que no cumple con las reglas {broken_rules(temp_clave3, rules, min_length)}. Usuario no creado.\n")
                                        else:
                                            claves[user3] = temp_clave3
                                            ofile.write(f"✓ Usuarios {user1} y {user2} fusionados exitosamente en el usuario {user3} de contraseña\n")
                                    else:
                                        ofile.write(f"✗ ERROR: Usuario {user1} o {user2} no registrado.\n")
                                else:
                                    ofile.write(f"✗ ERROR: argumento \"{command_pattern.findall(line)[3][1]}\" no registrado para comando FUSION PASSWORD\n")
                    case 6:
                        if command_pattern.findall(line)[0][0] == "CHANGE":
                            if command_pattern.findall(line)[1][1] != "PASSWORD":
                                ofile.write(f"✗ ERROR: argumento \"{command_pattern.findall(line)[1][1]}\" invalido, se esperaba \"PASSWORD\".\n")
                                if command_pattern.findall(line)[2][1] != "FROM":
                                    ofile.write(f"✗ ERROR: argumento \"{command_pattern.findall(line)[2][1]}\" invalido, se esperaba \"FROM\".\n")
                                else:
                                    if command_pattern.findall(line)[2][1]  in claves:
                                        if(broken_rules(command_pattern.findall(line)[4][1], rules, min_length)):
                                            ofile.write(f"✗ ERROR: Contraseña {command_pattern.findall(line)[4][1]} no valida para el usuario {command_pattern.findall(line)[2][1]} debido a que no cumple con las reglas {broken_rules(command_pattern.findall(line)[3][1], rules, min_length)}. No se realizaron cambios.\n")
                                        else:
                                            claves[command_pattern.findall(line)[2][1]] = command_pattern.findall(line)[4][1]
                                            ofile.write(f"✓ Contraseña {command_pattern.findall(line)[4][1]} actualizada para el usuario {command_pattern.findall(line)[2][1]} exitosamente.\n")
                                    else:
                                        ofile.write(f"✗ ERROR: Usuario {command_pattern.findall(line)[2][1]} no registrado.\n")
                    case _:
                        ofile.write(f"Comando igresado \"{line}\" no reconocido.\n")
    ofile.close()
    ifile.close()                   
            

def broken_rules(password, rules, min_length):
    """ <h1>broken_rules(password, rules, min_length)</h1>
    @brief Verifica si una contraseña cumple con las reglas especificadas y la longitud mínima.
    @param password:   ***(string) Contraseña a verificar.***
    @param rules:      ***(dict) Reglas de contraseña.***
    @param min_length: ***(int) Longitud mínima de la contraseña.***
    @return: - (list) Lista de reglas que no se cumplen.
    
    """
    broken_rules = []
    if(len(password) < min_length):
        broken_rules.append("MINIMUM_SIZE")
        
    for rule in rules:
        rule_regex = "["
        for char in rules[rule]:
            rule_regex += char
        rule_regex += "]"
        
        rule_patern= re.compile(rule_regex)
        if rule_patern.search(password):
            broken_rules.append(rule)            

    return broken_rules

def main():
    log_file = 'logSansano.txt'
    response = 'Resultados.txt'
    process_log(log_file, response)

if __name__ == "__main__":
    main()