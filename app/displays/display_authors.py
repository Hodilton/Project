import tkinter as tk
from tkinter import messagebox

from .display_base import DisplayBase

class DisplayAuthors(DisplayBase):
    def __init__(self, parent, db_manager):
        self.table_authors = db_manager.tables['authors']
        self.inputs = {}

        super().__init__(parent, db_manager)

    def open_form_window(self, mode):
        self.form_window_geometry = "900x100"
        super().open_form_window(mode)

    def create_form(self):
        tk.Label(self.form_window, text="Фамилия").grid(row=0, column=0, padx=10, pady=5)
        self.inputs['a_last_name'] = tk.Entry(self.form_window, width=30)
        self.inputs['a_last_name'].grid(row=0, column=1, padx=10, pady=5)

        tk.Label(self.form_window, text="Имя").grid(row=0, column=2, padx=10, pady=5)
        self.inputs['a_middle_name'] = tk.Entry(self.form_window, width=30)
        self.inputs['a_middle_name'].grid(row=0, column=3, padx=10, pady=5)

        tk.Label(self.form_window, text="Отчество").grid(row=0, column=4, padx=10, pady=5)
        self.inputs['a_second_name'] = tk.Entry(self.form_window, width=30)
        self.inputs['a_second_name'].grid(row=0, column=5, padx=10, pady=5)

    def fill_form_with_selected_item(self):
        selected_index = self.listbox.curselection()
        if selected_index:
            selected_data = self.listbox.get(selected_index).split(":")
            self.update_item_id = int(selected_data[0])
            a_last_name, a_middle_name, a_second_name = selected_data[1].split("-")

            self.inputs['a_last_name'].delete(0, tk.END)
            self.inputs['a_last_name'].insert(0, a_last_name.strip())

            self.inputs['a_middle_name'].delete(0, tk.END)
            self.inputs['a_middle_name'].insert(0, a_middle_name.strip())

            self.inputs['a_second_name'].delete(0, tk.END)
            self.inputs['a_second_name'].insert(0, a_second_name.strip())

    def add_or_update_item(self, mode):
        a_last_name = self.inputs['a_last_name'].get().strip()
        a_middle_name = self.inputs['a_middle_name'].get().strip()
        a_second_name = self.inputs['a_second_name'].get().strip()

        if a_last_name and a_middle_name and a_second_name:
            if mode is "add":
                self.table_authors.insert_data((a_last_name, a_middle_name, a_second_name))
            elif mode is "update":
                self.table_authors.update_data((a_last_name, a_middle_name, a_second_name), (self.id_to_update,))

            self.update_listbox()
            self.form_window.destroy()
        else:
            messagebox.showerror("Ошибка", "Введите корректные данные")

    def delete_item(self):
        super().delete_item()

        self.table_authors.delete_data((self.id_to_delete,))
        self.update_listbox()

    def update_listbox(self):
        self.listbox.delete(0, tk.END)
        self.data = self.table_authors.fetch_all()
        super().update_listbox()
