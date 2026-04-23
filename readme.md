# minitalk

UNIX sinyalleri (`SIGUSR1` / `SIGUSR2`) kullanarak iki process arasında string iletişimi sağlayan 42 İstanbul projesi.

## Nasıl Çalışır?

Client, mesajdaki her karakteri bit bit ikili sinyale dönüştürür ve server'ın PID'ine gönderir. Server sinyalleri alarak bitleri karaktere çevirir ve ekrana yazdırır.

- `SIGUSR1` → bit 0
- `SIGUSR2` → bit 1

## Kullanım

```bash
make

# Server'ı başlat (PID'i not al)
./server

# Client ile mesaj gönder
./client <SERVER_PID> "mesajın"
```

## Dosyalar

| Dosya        | Açıklama                  |
|--------------|---------------------------|
| `server.c`   | Sinyalleri alır, yazdırır |
| `client.c`   | Mesajı bit bit iletir     |
| `minitalk.h` | Header                    |
| `ft_printf/` | Çıktı için ft_printf      |

## Teknolojiler

`SIGUSR1/2` · `sigaction` · `kill` · `getpid` · C

---

**bakarabu** — 42 İstanbul
