# PUSH_SWAP İŞ BÖLÜMÜ

Projeyi Serhat ve Fatih birlikte geliştirecek.

Yaklaşık iş yükü:

Serhat: %70
Fatih: %30

İkimiz de finalde projenin tamamını anlayacak ve herhangi bir kısmını açıklayabilecek durumda olacağız.

==================================================
SERHAT'IN SORUMLULUKLARI
==================================================

1. PROJE MİMARİSİ

- Projenin genel yapısını oluşturmak
- Dosya yapısını belirlemek
- Stack veri yapısını tasarlamak
- Node / stack yapısını oluşturmak
- Memory management düzenini oluşturmak
- Ortak utility fonksiyonlarını hazırlamak
- Projenin farklı bölümlerinin birbirleriyle bağlantısını kurmak


2. STACK OPERATIONS

Bütün push_swap operationlarının implementation'ı Serhat tarafından yapılacak.

- sa
- sb
- ss
- pa
- pb
- ra
- rb
- rr
- rra
- rrb
- rrr

Operationların:

- Stackleri doğru şekilde değiştirmesi
- Boş veya tek elemanlı stacklerde hata vermemesi
- Doğru operation çıktısını üretmesi
- Benchmark counter sistemiyle çalışması
- Gereksiz operation üretmemesi

sa:
Stack A'nın ilk iki elemanını swap eder.

sb:
Stack B'nin ilk iki elemanını swap eder.

ss:
sa ve sb işlemlerini birlikte yapar.

pa:
Stack B'nin en üstündeki elemanı Stack A'ya taşır.

pb:
Stack A'nın en üstündeki elemanı Stack B'ye taşır.

ra:
Stack A'yı rotate eder.

rb:
Stack B'yi rotate eder.

rr:
ra ve rb işlemlerini birlikte yapar.

rra:
Stack A'yı reverse rotate eder.

rrb:
Stack B'yi reverse rotate eder.

rrr:
rra ve rrb işlemlerini birlikte yapar.


3. DISORDER HESAPLAMA

- Başlangıç stackinin disorder değerini hesaplamak
- Disorder hesabını herhangi bir sorting operation yapılmadan önce yapmak
- Inversion / yanlış sıralanmış pair sayısını hesaplamak
- Disorder değerini 0 ile 1 arasında üretmek
- Adaptive algoritmaya disorder bilgisini sağlamak


4. MEDIUM SORTING ALGORITHM

- O(n√n) complexity sınıfında çalışan algoritmayı yazmak
- Chunk / range / block tabanlı uygun yöntemi belirlemek
- Stack A ve B arasında uygun dağılım yapmak
- Rotate yönlerini optimize etmek
- Gereksiz operation sayısını azaltmak
- Bütün geçerli inputlarda doğru sonuç üretmek


5. COMPLEX SORTING ALGORITHM

- O(n log n) complexity sınıfında çalışan algoritmayı yazmak
- Radix veya şartları karşılayan başka uygun bir yöntem kullanmak
- Gerekirse coordinate compression yapmak
- Büyük inputlarda stabil şekilde çalışmasını sağlamak
- Operation sayısını optimize etmek
- 100 ve 500 sayı testlerinde iyi performans elde etmeye çalışmak


6. ADAPTIVE SORTING ALGORITHM

Disorder değerine göre farklı strategy kullanacak adaptive sistemi yazmak.

Temel seçim:

disorder < 0.20
-> low disorder yöntemi

0.20 <= disorder < 0.50
-> medium disorder yöntemi

disorder >= 0.50
-> high disorder yöntemi

Adaptive sistemin:

- Doğru disorder değerini kullanması
- Doğru internal algoritmayı seçmesi
- Complexity şartlarını karşılaması
- Bütün valid inputlarda doğru çalışması

sağlanacak.


7. STRATEGY SİSTEMİ

Aşağıdaki strategy seçeneklerini sisteme bağlamak:

--simple
--medium
--complex
--adaptive

Flag verilmediğinde adaptive strategy kullanılacak.

Fatih'in yazdığı simple algoritma da bu sisteme Serhat tarafından entegre edilecek.


8. PERFORMANCE OPTIMIZATION

- Operation sayılarını azaltmak
- Gereksiz rotate işlemlerini bulmak
- Gereksiz reverse rotate işlemlerini azaltmak
- Uygun durumlarda combined operations kullanmak:

ss
rr
rrr

- 100 random sayı testlerini optimize etmek
- 500 random sayı testlerini optimize etmek
- Farklı disorder seviyelerinde algoritmaların davranışını incelemek
- Performance sonuçlarına göre algoritmaları geliştirmek


9. FINAL INTEGRATION

- Parser ile stack yapısını bağlamak
- Stack operations ile algoritmaları bağlamak
- Simple algoritmayı sisteme eklemek
- Medium algoritmayı sisteme eklemek
- Complex algoritmayı sisteme eklemek
- Adaptive algoritmayı sisteme eklemek
- Benchmark sistemini sorting sistemine bağlamak
- Bütün mandatory özelliklerin birlikte çalışmasını sağlamak


10. MAKEFILE VE GENEL KONTROLLER

- Makefile hazırlamak
- Gereksiz relink olmamasını sağlamak
- Norm kontrollerini yapmak
- Compile kontrollerini yapmak
- Memory leak kontrollerini yapmak
- Invalid read / invalid write kontrollerini yapmak
- Final mandatory testlerini yapmak


11. TEKNİK DOKÜMANTASYON

- Disorder sistemini açıklamak
- Medium algoritmayı açıklamak
- Complex algoritmayı açıklamak
- Adaptive algoritmayı açıklamak
- Strategy seçiminin mantığını açıklamak
- Algoritmaların complexity mantığını açıklamak
- Performance yaklaşımını açıklamak


==================================================
FATİH'İN SORUMLULUKLARI
==================================================

1. PARSER VE INPUT VALIDATION

Parser sisteminin tamamından Fatih sorumlu olacak.

- Argumentleri parse etmek
- Girilen değerlerin integer olup olmadığını kontrol etmek
- Pozitif sayıları işlemek
- Negatif sayıları işlemek
- INT_MIN kontrolü yapmak
- INT_MAX kontrolü yapmak
- Integer overflow kontrolü yapmak
- Integer underflow kontrolü yapmak
- Duplicate değerleri tespit etmek
- Geçersiz karakterleri yakalamak
- Empty string kontrolü yapmak
- Hatalı inputları yakalamak
- Hata durumunda Error\n çıktısını doğru yere göndermek
- Parsing sırasında ayrılan memory alanlarını doğru yönetmek
- Memory leak oluşturmamak

Parser sonucunda Serhat'ın oluşturduğu stack yapısına aktarılabilecek temiz input oluşturulacak.


2. SIMPLE SORTING ALGORITHM

Fatih O(n²) complexity sınıfında çalışan simple algoritmayı yazacak.

Kullanılabilecek yöntemlerden biri seçilebilir:

- Selection sort adaptation
- Insertion sort adaptation
- Min extraction
- Max extraction
- Benzer basit O(n²) yaklaşım

Algoritmanın:

- Doğru sorting yapması
- Stack A'yı ascending sıralaması
- Sorting sonunda Stack B'yi boş bırakması
- Bütün valid inputlarda çalışması
- Küçük inputlarda hata vermemesi
- Gereksiz operation sayısını mümkün olduğunca azaltması

gerekiyor.


3. BENCHMARK COUNTER SİSTEMİ

Bütün operationların kaç kez kullanıldığını takip eden sistemi hazırlamak.

Takip edilecek değerler:

sa_count
sb_count
ss_count
pa_count
pb_count
ra_count
rb_count
rr_count
rra_count
rrb_count
rrr_count

Ayrıca:

total_operations

hesaplanacak.

Benchmark çıktısında:

- Disorder değeri
- Kullanılan strategy
- Strategy complexity bilgisi
- Total operation sayısı
- Her operationın ayrı kullanım sayısı

gösterilecek.

Benchmark bilgileri stderr üzerinden çıkacak.

Normal push_swap operationları stdout üzerinde kalacak.


4. TESTING

Testing sisteminin ana sorumluluğu Fatih'te olacak.

Parser testleri:

- Argument verilmemesi
- Tek sayı
- İki sayı
- Pozitif sayılar
- Negatif sayılar
- INT_MIN
- INT_MAX
- Overflow
- Underflow
- Duplicate
- Harf içeren input
- Karışık valid / invalid input
- Empty string
- Geçersiz karakterler

Sorting testleri:

- 1 sayı
- 2 sayı
- 3 sayı
- 5 sayı
- 10 sayı
- Already sorted input
- Reverse sorted input
- Negative input
- Positive ve negative karışık input
- Random input
- Low disorder input
- Medium disorder input
- High disorder input

Bütün strategyler ayrı test edilecek:

--simple
--medium
--complex
--adaptive

Kontrol edilecekler:

- Sorting doğru mu
- Stack A sorted mı
- Stack B boş mu
- Checker OK veriyor mu
- Program crash oluyor mu
- Memory leak var mı
- Yanlış input Error veriyor mu
- Benchmark doğru çalışıyor mu


5. RANDOM VE PERFORMANCE TESTLERİ

Fatih düzenli olarak random testler çalıştıracak.

Özellikle:

- 100 random sayı
- 500 random sayı

Operation sayıları kaydedilecek.

Farklı algoritmaların sonuçları karşılaştırılacak.

Problemli veya yüksek operation üreten inputlar Serhat'a bildirilecek ve algoritmalar birlikte incelenecek.


6. BENCHMARK TESTLERİ

Benchmark sisteminde şunların doğru olduğundan emin olunacak:

- Disorder değeri doğru mu
- Strategy adı doğru mu
- Complexity bilgisi doğru mu
- Total operation doğru mu
- Her operation counterı doğru mu
- stdout temiz mi
- stderr doğru mu


7. README / KULLANIM DOKÜMANTASYONU

Fatih aşağıdaki bölümleri hazırlayacak:

- Programın compile edilmesi
- Programın çalıştırılması
- Strategy flaglerinin kullanımı
- Parser davranışı
- Error handling
- Testing yöntemleri
- Benchmark kullanım örnekleri
- Simple algoritmanın açıklaması


8. BONUS CHECKER

Mandatory kısım tamamen bittikten sonra bonus checker'ın ana implementationı Fatih tarafından yapılacak.

Checker:

- Stack inputunu parse edecek
- stdin üzerinden operationları okuyacak
- Operationları stackler üzerinde uygulayacak
- Stack A sorted ve Stack B empty ise:

OK

yazacak.

Diğer durumlarda:

KO

yazacak.

Invalid input veya invalid operation durumunda:

Error

verecek.

Checker'ın:

- Parser
- Operation validation
- stdin okuma
- Operation execution
- Final stack kontrolü
- Error handling

kısımlarının ana sorumluluğu Fatih'te olacak.


==================================================
ORTAK SORUMLULUKLAR
==================================================

Serhat ve Fatih:

- Birbirlerinin yaptığı kodları okuyacak
- Bütün stack operationlarını anlayacak
- Parserın nasıl çalıştığını anlayacak
- Disorder hesabını anlayacak
- Simple algoritmayı anlayacak
- Medium algoritmayı anlayacak
- Complex algoritmayı anlayacak
- Adaptive algoritmayı anlayacak
- Complexity farklarını anlayacak
- Strategy selection sistemini anlayacak
- Benchmark sistemini anlayacak
- Edge case testleri yapacak
- Memory leak kontrolü yapacak
- Checker ile test yapacak
- Performance sonuçlarını inceleyecek
- Final projedeki herhangi bir kısmı açıklayabilecek durumda olacak


==================================================
KISA ÖZET
==================================================

SERHAT:

- Proje mimarisi
- Stack yapısı
- Stack operations
- Memory yapısı
- Disorder
- Medium algorithm
- Complex algorithm
- Adaptive algorithm
- Strategy selection
- Performance optimization
- Sorting integration
- Makefile
- Final integration
- Teknik algoritma dokümantasyonu


FATİH:

- Parser
- Input validation
- Error handling
- Simple algorithm
- Benchmark counter sistemi
- Benchmark output
- Automated / manual testing
- Random testler
- Performance testleri
- Kullanım dokümantasyonu
- Bonus checker
