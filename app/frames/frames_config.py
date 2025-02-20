from app.displays.display_base import DisplayBase
from app.displays.display_genres import DisplayGenres
from app.displays.book_statuses import DisplayBookStatuses
from app.displays.display_books import DisplayBooks
from app.displays.display_authors import DisplayAuthors
from app.displays.display_departments import DisplayDepartments
from app.displays.display_librarians import DisplayLibrarians
from app.displays.display_readers import DisplayReaders
from app.displays.display_borrowed_books import DisplayBorrowedBooks

frames_config = {

    "Выдача": {

        "borrowed_books": {
            "class": DisplayBorrowedBooks,
            "name": "Выданные книги",
        },

    },

    "Книги": {

        "books": {
            "class": DisplayBooks,
            "name": "Книги",
        },

        "genres": {
            "class": DisplayGenres,
            "name": "Жанры",
        },

        "book_statuses": {
            "class": DisplayBookStatuses,
            "name": "Статус книги",
        },

        "authors": {
            "class": DisplayAuthors,
            "name": "Авторы",
        },
    },

    "Сотрудники": {

        "librarians": {
            "class": DisplayLibrarians,
            "name": "Сотрудники",
        },

        "departments": {
            "class": DisplayDepartments,
            "name": "Должности",
        },

    },

    "Читатели": {

        "readers": {
            "class": DisplayReaders,
            "name": "Читатели",
        },

    },
}