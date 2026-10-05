class SmartDevice:
    def __init__(self, i="kosong", n="kosong", t="kosong"):
        self._id = i
        self._name = n
        self._type = t

    def get_id(self):
        return self._id

    def get_name(self):
        return self._name

    def get_type(self):
        return self._type

    def set_id(self, text):
        self._id = text

    def set_name(self, text):
        self._name = text

    def set_type(self, text):
        self._type = text

    def get_val(self):
        pass

    def set_val(self, val):
        pass


class SmartLight(SmartDevice):
    def __init__(self, i="kosong", n="kosong", b=0):
        super().__init__(i, n, "Light")
        self._brightness = int(b)

    def get_val(self):
        return self._brightness

    def set_val(self, val):
        self._brightness = int(val)


class SmartThermostat(SmartDevice):
    def __init__(self, i="kosong", n="kosong", t=0):
        super().__init__(i, n, "Thermostat")
        self._temperature = int(t)

    def get_val(self):
        return self._temperature

    def set_val(self, val):
        self._temperature = int(val)


class SmartSpeaker(SmartDevice):
    def __init__(self, i="kosong", n="kosong", v=0):
        super().__init__(i, n, "Speaker")
        self._volume = int(v)

    def get_val(self):
        return self._volume

    def set_val(self, val):
        self._volume = int(val)