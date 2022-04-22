# user_sign

Для того чтобы запустить работу сигнала, нужно:
1. Зайти в эту папку и прописать в консоли ```gcc one.c -o one``` и ```gcc two.c -o two```
2. Далее как все скомпилируется дублировать терминал в этой папку
3. В первом терминале запустить программу one командой ```./one``` после должна появиться строка PID = *PID_NUMBER*, сохраняем *PID_NUMBER* в буфер обмена(p.s. *PID_NUMBER*, это число)
4. Во втором терминале запускаем программу two командой ```./two PID_NUMBER SIG```, и вместо SIG пишем либо SIGUSR1, либо SIGUSR2, и замечаем результат в первом терминале
