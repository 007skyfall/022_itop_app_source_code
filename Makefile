#���빤����g++����ͬʱ֧��C��C++�����Լ����ߵĻ�ϱ���
CC=g++

#����sources�õ���ǰĿ¼�´������.c/.cpp�ļ����б������ε���wildcard���������һ�𼴿�
sources:=$(wildcard *.c) $(wildcard *.cpp)

#����objects�õ������ɵ�.o�ļ����б�����sources��ÿ���ļ�����չ������.o���ɡ��������ε���patsubst��������1�ΰ�sources������.cpp����.o����2�ΰѵ�1�ν��������.c����.o
objects:=$(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(sources)))

#����dependence�õ������ɵ�.d�ļ����б�����objects��ÿ����չ��.o����.d���ɡ�Ҳ��д��$(patsubst %.o,%.d,$(objects))
dependence:=$(objects:.o=.d)

#��$(objects)�б��������ļ������ɺ󣬱�ɵ�������� $(CC) $^ -o $@ ������������Ŀ��all
#��all����ɵ�1������ʹ�ÿ��԰�make all�����д��make
all: $(objects)
	$(CC) $(CPPFLAGS) $^ -o $@
	@./$@	#���������ִ��

#���ʹ��make��ģʽ����ָʾ�����.c�ļ�����.o������ÿ��.c�ļ�������gcc -c XX.c -o XX.o�������ɶ�Ӧ��.o�ļ�
#�����д���Ҳ���ԣ���Ϊmake���������������ͬ����Ч��
%.o: %.c
	$(CC) $(CPPFLAGS) -c $< -o $@

#ͬ�ϣ�ָʾ�����.cpp����.o����ʡ��
%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

include $(dependence)	#ע��þ�Ҫ�����ռ�Ŀ��all�Ĺ���֮�󣬷���.d�ļ���Ĺ���ᱻ�����ռ�������

#��Ϊ��4������Ҫ��ε��ã������������Լ���д
define gen_dep
set -e; rm -f $@; \
$(CC) -MM $(CPPFLAGS) $< > $@.$$$$; \
sed 's,\($*\)\.o[ :]*,\1.o $@ : ,g' < $@.$$$$ > $@; \
rm -f $@.$$$$
endef

#ָʾ�����.c���������������ļ�.d
#���ʹ��make��ģʽ����ָʾ��ÿ��.c�ļ���������������������ļ�.d��������������������
%.d: %.c
	$(gen_dep)

#ͬ�ϣ�ָʾ��ÿ��.cpp��������������������ļ�.d
%.d: %.cpp
	$(gen_dep)

#���������ʱ�ļ�������.o��.d����֮���԰�clean�����αĿ�꣬����Ϊ���Ŀ�겢����Ӧʵ�ʵ��ļ�
.PHONY: clean
clean:	#.$$����ÿ��ʹ�ú�����ɾ����-f������ʾ��ɾ�ļ�������ʱ������
	rm -f all $(objects) $(dependence)

echo:	#����ʱ��ʾһЩ������ֵ
	@echo sources=$(sources)
	@echo objects=$(objects)
	@echo dependence=$(dependence)
	@echo CPPFLAGS=$(CPPFLAGS)

#���ѣ�����ϱ���.c/.cppʱ��Ϊ���ܹ���C++���������C�����������ÿһ��Ҫ���õ�C��������������������extern "C"{}�����棬����C++����ʱ���ܳɹ��������ǡ�