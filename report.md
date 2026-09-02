# Push Swap İlerleme Raporu

## Mevcut Durum

Sorting core şu anda `main` branch üzerinde çalışıyor ve test edildi.

Son test edilen commit:

`0199578608eebd68c6c3094a72dd9fa067ec55d8` — `sorting algorithm improvements`

Program şu anda şunları destekliyor:

- varsayılan adaptive strategy
- `--adaptive`
- `--simple`
- `--medium`
- `--complex`
- normal argv kullanımı: `./push_swap 3 2 1`
- quoted input: `./push_swap "3 2 1"`
- duplicate kontrolü
- geçersiz sayı kontrolü
- negatif ve pozitif integerlar
- `INT_MIN` ve `INT_MAX`
- input zaten sıralıysa hiç operation yazmama

---

## Tamamlanan Sorting Strategy'leri

### Simple

Selection/minimum-extraction mantığı kullanılıyor.

Şu anki davranış:

- sorting başlamadan önce index atanıyor
- hedef eleman stack içinde bulunuyor
- hedef üste getirilirken daha kısa yön seçiliyor
- hedef ikinci sıradaysa gereksiz rotate yerine `sa` kullanılıyor
- son kalan eleman gereksiz yere B'ye pushlanmıyor
- kalan A zaten sıralıysa erken çıkılıyor

İlk implementasyona göre gereksiz operationlar azaltıldı.

### Medium

Yaklaşık `sqrt(n)` bucket kullanan bucket-based strategy.

`math.h` kullanılmıyor, bucket sayısı manuel hesaplanıyor.

Şu anki davranış:

- önce index atanıyor
- bucket size manuel hesaplanıyor
- en yüksek bucket gereksiz yere B'ye taşınıp geri alınmıyor
- ilk bucket pass sonunda A sıralandıysa ikinci pass çalıştırılmıyor

Bu yapı medium strategy için istenen bucket yaklaşımına uyuyor.

### Complex

Indexler üzerinde binary radix sort kullanılıyor.

Şu anki davranış:

- indexler `0` ile `n - 1` arasında
- indexler bit bit işleniyor
- current bit için gerekli bütün `1` elemanları işlendiğinde pass erken durabiliyor
- gereksiz trailing push/restore işlemleri azaltıldı
- A bütün bitler bitmeden sıralanırsa radix erken bitiyor

---

## Adaptive Strategy

Adaptive mode inversion ratio üzerinden disorder hesaplıyor.

Şu thresholdlar kullanılıyor:

- disorder `< 0.2` → simple
- disorder `< 0.5` → medium
- diğer durumlar → complex/radix

Herhangi bir strategy flag verilmezse varsayılan olarak adaptive çalışıyor.

---

## Yapılan Testler

### Edge Case Testleri

Şunlar başarıyla test edildi:

- tek sayı
- zaten sıralı input
- ters sıralı iki sayı
- reverse sorted input
- negatif ve pozitif sayıların karışımı
- `2147483647`
- `-2147483648`
- duplicate sayı
- quoted input

Test edilen örnekler:

```text
1
1 2
2 1
1 2 3 4 5
5 4 3 2 1
-5 10 0 -20 3
2147483647 -2147483648 0
1 1
"5 2 -3 10 0"
```

Duplicate input doğru şekilde:

```text
Error
```

yazdırıyor.

### Strategy Correctness Testi

Aynı 10 elemanlık input bütün strategy'lerle test edildi.

Sonuç:

```text
simple   -> OK, 32 operation
medium   -> OK, 53 operation
complex  -> OK, 45 operation
adaptive -> OK, 45 operation
```

Her testte:

- A sıralı bitti
- B boş bitti
- eleman sayısı korundu

### Random 100 Eleman Testleri

Complex strategy ile 20 farklı random permutation test edildi.

20/20 test geçti.

Operation sayıları:

```text
minimum: 1010
maximum: 1024
```

Verilen limitlerin rahat şekilde altında.

### Random 500 Eleman Testleri

Complex strategy ile 10 farklı random permutation test edildi.

10/10 test geçti.

Operation sayıları:

```text
minimum: 6736
maximum: 6752
```

Bu da verilen limitlerin rahat şekilde altında.

Şimdilik sorting core üzerinde daha fazla optimizasyon yapmaya gerek yok.

---

## Kalan Önemli İşler

Burada sadece gerçekten problem çıkarabilecek veya proje için eksik olan şeyler var. Norm format temizliği ayrı tutuldu.

### 1. `--bench` henüz yapılmadı

Benchmark mode eklenmesi gerekiyor.

`stderr` üzerinden şunların yazdırılması gerekiyor:

- disorder yüzdesi
- seçilen strategy
- theoretical complexity
- toplam operation sayısı
- ayrı ayrı:
  - `sa`
  - `sb`
  - `ss`
  - `pa`
  - `pb`
  - `ra`
  - `rb`
  - `rr`
  - `rra`
  - `rrb`
  - `rrr`

Normal sorting operationları sadece `stdout` üzerinden yazılmaya devam etmeli.

### 2. Operation counter sistemi yok

Operation fonksiyonları şu anda direkt instruction yazdırıyor.

Bench için sadece gerçekten yazdırılan operationların sayılması gerekiyor.

Bu eklenirken sorting davranışı değiştirilmemeli.

### 3. `ft_atol` overflow kontrolü güçlendirilmeli

Şu an range check parsing bittikten sonra yapılıyor.

Aşırı büyük bir numeric string verilirse `long`, final INT range kontrolüne gelmeden önce overflow olabilir.

Örnek:

```text
999999999999999999999999999999999999
```

Bu yüzden digitler okunurken overflow kontrolü yapılması gerekiyor.

Geçerli aralık:

```text
-2147483648 ile 2147483647
```

olmalı.

### 4. `ft_add_back` içinde latent bug var

Şu anki mantıkta:

```c
if (!*stack || !new)
{
    *stack = new;
    return ;
}
```

var.

Eğer `new == NULL` ve stack doluysa mevcut stack pointer `NULL` yapılabilir.

Parser şu an allocation başarısızlığını önceden kontrol ettiği için testlerde patlamadı ama fonksiyonun kendisi güvenli değil.

Mantık şu şekilde düzeltilmeli:

```c
if (!new)
    return ;
if (!*stack)
{
    *stack = new;
    return ;
}
```

### 5. Strategy flag edge case'leri son kez kontrol edilmeli

Normal strategy kullanımları çalışıyor ama şu tarz durumlar ayrıca test edilmeli:

```text
./push_swap --simple
./push_swap --medium
./push_swap --complex
./push_swap --adaptive
./push_swap --unknown 1 2 3
```

`--bench` eklendiğinde strategy flag ile beraber kullanımı da düzgün parse edilmeli.

### 6. Final Linux testi yapılmadı

Geliştirme ve testlerin büyük kısmı Windows'ta yapıldı.

Finalde 42 Linux ortamında şunlar yapılmalı:

- gerçek compiler flagleri
- Norminette
- checker
- Valgrind / leak testi
- invalid input testleri
- random 100 testleri
- random 500 testleri

Windows'ta `ft_atol` içinde `long` boyutundan kaynaklanan bir warning var. Final target 42 Linux olsa da overflow kontrolü yine ayrıca düzeltilmeli.

### 7. Makefile henüz yok

Final proje için Makefile eklenmesi ve test edilmesi gerekiyor.

### 8. Teknik dokümantasyon henüz tamamlanmadı

Final dokümantasyonda şunlar açıklanmalı:

- simple strategy ve complexity upper bound
- medium strategy ve neden `O(n sqrt(n))`
- complex/radix strategy ve `O(n log n)`
- disorder hesabı
- adaptive thresholdlar
- benchmark davranışı

---

## Temizlik İçin Kalanlar

Bunlar şu an algorithm bugı değil ama evaluation öncesi temizlenmeli:

- debug amaçlı `print_stack` kaldırılmalı
- kullanılmayan `stdio.h` kaldırılmalı
- `push_swap.h` içindeki duplicate prototypelar temizlenmeli
- bazı dosyalardaki eski 42 header dosya isimleri düzeltilmeli
- Norminette için uzun fonksiyonlar bölünmeli
- `push_swap_util.c` içindeki fazla fonksiyonlar mantıklı dosyalara ayrılmalı
- geçici commentler silinmeli
- final compile `-Wall -Wextra -Werror` ile yapılmalı

Bu refactorlarda test edilmiş sorting mantığı değiştirilmemeli.

---

## Bundan Sonra Önerilen Sıra

1. `--bench` argument handling
2. operation counterlar
3. benchmark bilgisini `stderr` üzerinden yazdırma
4. `ft_atol` overflow fix
5. `ft_add_back` fix
6. kalan argument edge case testleri
7. Makefile
8. Norminette refactor ve format temizliği
9. refactor sonrası aynı 100/500 correctness testlerini tekrar çalıştırma
10. Linux checker/leak/error testleri
11. README / teknik dokümantasyon

---

## Sonuç

Ana sorting algoritmaları şu an implement edilmiş, test edilmiş ve verilen operation limitlerinin içinde çalışıyor.

Şu aşamada en büyük eksikler sorting optimizasyonu değil:

- benchmark sistemi
- parser hardening
- `ft_add_back` fix
- Makefile
- Linux final validation
- Norminette refactor
- final dokümantasyon
