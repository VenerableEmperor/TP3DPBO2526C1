import sys
from device import SmartDevice, SmartLight, SmartThermostat, SmartSpeaker

def title():
    print("==============================================")
    print("||       SMART HOME DEVICE MANAGER!         ||")
    print("==============================================")
    print()

def helpmenu():
    print("==============================================")
    print("||              COMMAND LIST                ||")
    print("||                 +INPUT                   ||")
    print("||                 +SHOW                    ||")
    print("||                 +UPDATE                  ||")
    print("||                 +DELETE                  ||")
    print("||                 +SEARCH                  ||")
    print("||                 +HELP                    ||")
    print("||                                          ||")
    print("||+ FORMAT INPUT :                          ||")
    print("||INPUT type(LIGHT/THERMO/SPEAKER) id name  ||")
    print("||value                                     ||")
    print("||                                          ||")
    print("||+ FORMAT SHOW :                           ||")
    print("||SHOW                                      ||")
    print("||                                          ||")
    print("||+ FORMAT UPDATE :                         ||")
    print("||UPDATE id name value                      ||")
    print("||                                          ||")
    print("||+ FORMAT DELETE :                         ||")
    print("||DELETE id                                 ||")
    print("||                                          ||")
    print("||+ FORMAT SEARCH :                         ||")
    print("||SEARCH id                                 ||")
    print("||                                          ||")
    print("||+ FORMAT HELP :                           ||")
    print("||HELP                                      ||")
    print("==============================================")

def search(id_target, datadevice):
    for dev in datadevice:
        if dev.get_id() == id_target:
            return dev
    return None

def updateDevice(id_target, datadevice, newname, newval):
    terupdate = False
    for dev in datadevice:
        if dev.get_id() == id_target:
            dev.set_name(newname)
            dev.set_val(int(newval))
            terupdate = True
    return terupdate

def deleteDevice(id_target, datadevice):
    ketemu = False
    for i in range(len(datadevice)):
        if datadevice[i].get_id() == id_target:
            ketemu = True
            datadevice.pop(i)
            break
    return ketemu

def hitungpanjang(datadevice):
    pid, pname, ptype, pval = 2, 11, 11, 5
    for dev in datadevice:
        if len(dev.get_id()) > pid:
            pid = len(dev.get_id())
        if len(dev.get_name()) > pname:
            pname = len(dev.get_name())
        if len(dev.get_type()) > ptype:
            ptype = len(dev.get_type())
        if len(str(dev.get_val())) > pval:
            pval = len(str(dev.get_val()))
    return pid, pname, ptype, pval

def judul(pid, pname, ptype, pval, pall):
    for _ in range(pall):
        print("=", end="")
    print()

    sid = pid + 1 - 2
    print("|ID", end="")
    for _ in range(int(sid)):
        print(" ", end="")

    sname = pname + 1 - 11
    print("|DEVICE NAME", end="")
    for _ in range(int(sname)):
        print(" ", end="")

    stype = ptype + 1 - 11
    print("|DEVICE TYPE", end="")
    for _ in range(int(stype)):
        print(" ", end="")

    sval = pval + 1 - 5
    print("|VALUE", end="")
    for _ in range(int(sval)):
        print(" ", end="")
    print("|")

    for _ in range(pall):
        print("=", end="")
    print()

def showall(datadevice):
    print()
    pid, pname, ptype, pval = hitungpanjang(datadevice)
    pall = pid + pname + ptype + pval + 9
    judul(pid, pname, ptype, pval, pall)

    for dev in datadevice:
        sid = pid + 1 - len(dev.get_id())
        print("|" + dev.get_id(), end="")
        for _ in range(int(sid)):
            print(" ", end="")

        sname = pname + 1 - len(dev.get_name())
        print("|" + dev.get_name(), end="")
        for _ in range(int(sname)):
            print(" ", end="")

        stype = ptype + 1 - len(dev.get_type())
        print("|" + dev.get_type(), end="")
        for _ in range(int(stype)):
            print(" ", end="")

        sval = pval + 1 - len(str(dev.get_val()))
        print("|" + str(dev.get_val()), end="")
        for _ in range(int(sval)):
            print(" ", end="")
        print("|")

    for _ in range(pall):
        print("=", end="")
    print("\n")

def hitungpanjangsatu(dev):
    pid, pname, ptype, pval = 2, 11, 11, 5
    if len(dev.get_id()) > pid:
        pid = len(dev.get_id())
    if len(dev.get_name()) > pname:
        pname = len(dev.get_name())
    if len(dev.get_type()) > ptype:
        ptype = len(dev.get_type())
    if len(str(dev.get_val())) > pval:
        pval = len(str(dev.get_val()))
    return pid, pname, ptype, pval

def showsatu(dev):
    print()
    pid, pname, ptype, pval = hitungpanjangsatu(dev)
    pall = pid + pname + ptype + pval + 9
    judul(pid, pname, ptype, pval, pall)

    sid = pid + 1 - len(dev.get_id())
    print("|" + dev.get_id(), end="")
    for _ in range(int(sid)):
        print(" ", end="")

    sname = pname + 1 - len(dev.get_name())
    print("|" + dev.get_name(), end="")
    for _ in range(int(sname)):
        print(" ", end="")

    stype = ptype + 1 - len(dev.get_type())
    print("|" + dev.get_type(), end="")
    for _ in range(int(stype)):
        print(" ", end="")

    sval = pval + 1 - len(str(dev.get_val()))
    print("|" + str(dev.get_val()), end="")
    for _ in range(int(sval)):
        print(" ", end="")
    print("|")

    for _ in range(pall):
        print("=", end="")
    print("\n")

def main():
    title()
    helpmenu()
    datadevice = []
    
    while True:
        try:
            line = input("INPUT : ").strip()
            if not line:
                continue
            args = line.split()
            cmd = args[0]
            
            if cmd == "EXIT":
                break
            elif cmd == "INPUT":
                if len(args) >= 5:
                    tipe = args[1]
                    id_dev = args[2]
                    name = args[3]
                    val = int(args[4])
                    
                    if tipe == "LIGHT":
                        datadevice.append(SmartLight(id_dev, name, val))
                    elif tipe == "THERMO":
                        datadevice.append(SmartThermostat(id_dev, name, val))
                    elif tipe == "SPEAKER":
                        datadevice.append(SmartSpeaker(id_dev, name, val))
                    else:
                        datadevice.append(SmartLight(id_dev, name, val))
            elif cmd == "SHOW":
                showall(datadevice)
            elif cmd == "UPDATE":
                if len(args) >= 4:
                    id_target = args[1]
                    name = args[2]
                    val = args[3]
                    akhir = updateDevice(id_target, datadevice, name, val)
                    if akhir:
                        print("DATA DEVICE BERHASIL DIUPDATE!")
                    else:
                        print("DATA DEVICE GAGAL DIUPDATE!")
            elif cmd == "DELETE":
                if len(args) >= 2:
                    id_target = args[1]
                    hasil = deleteDevice(id_target, datadevice)
                    if hasil:
                        print("DEVICE YANG DIPILIH BERHASIL DIHAPUS!")
                    else:
                        print("DEVICE YANG DIPILIH GAGAL DIHAPUS!")
            elif cmd == "SEARCH":
                if len(args) >= 2:
                    id_target = args[1]
                    cari = search(id_target, datadevice)
                    if cari is not None:
                        showsatu(cari)
                    else:
                        print("ID DEVICE TIDAK COCOK DENGAN MANAPUN!")
            elif cmd == "HELP":
                helpmenu()
            else:
                print("COMMAND INVALID!")
        except Exception:
            pass

if __name__ == "__main__":
    main()