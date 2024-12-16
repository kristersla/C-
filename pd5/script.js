document.addEventListener("DOMContentLoaded", () => {

    const gallery = document.getElementById('gallery');
    const allFilter = document.getElementById('allFilter');
    const natureFilter = document.getElementById('natureFilter');
    const cityFilter = document.getElementById('cityFilter');
    const abstractFilter = document.getElementById('abstractFilter');
    const sortBy = document.getElementById('sortBy');
    const imageForm = document.getElementById('imageForm');
    const imageUrlInput = document.getElementById('imageUrl');
    const imageNameInput = document.getElementById('imageName');
    const imageCategoryInput = document.getElementById('imageCategory');
    const urlError = document.getElementById('urlError');
    const nameError = document.getElementById('nameError');
    const categoryError = document.getElementById('categoryError');

    let images = [];

    function createImageElement(imageData) {
        const imageItem = document.createElement('div');
        imageItem.classList.add('image-item');

        const img = document.createElement('img');
        img.src = imageData.url;
        img.alt = imageData.name;

        const imageInfo = document.createElement('p');
        imageInfo.textContent = `${imageData.name} - ${imageData.category} - Added: ${imageData.date}`;

        const removeButton = document.createElement('button');
        removeButton.textContent = 'Remove';
        removeButton.addEventListener('click', () => removeImage(imageData));

        imageItem.appendChild(img);
        imageItem.appendChild(imageInfo);
        imageItem.appendChild(removeButton);

        return imageItem;
    }

    function renderGallery(filter = 'All') {
        gallery.innerHTML = '';

        const filteredImages = filter === 'All' ? images : images.filter(image => image.category === filter);

        filteredImages.forEach(image => {
            const imageElement = createImageElement(image);
            gallery.appendChild(imageElement);
        });
    }

    function validateForm() {
        let valid = true;

        urlError.textContent = '';
        nameError.textContent = '';
        categoryError.textContent = '';

        const urlValue = imageUrlInput.value.trim();
        if (!urlValue.match(/\.(jpg|png|gif|svg)$/i)) {
            urlError.textContent = 'Invalid image URL. Must end with .jpg, .png, .gif, or .svg.';
            valid = false;
        }

        const nameValue = imageNameInput.value.trim();
        if (!nameValue) {
            nameError.textContent = 'Image name cannot be empty.';
            valid = false;
        }

        const categoryValue = imageCategoryInput.value;
        if (!categoryValue) {
            categoryError.textContent = 'Please select a category.';
            valid = false;
        }

        return valid;
    }

    imageForm.addEventListener('submit', function (e) {
        e.preventDefault();

        if (!validateForm()) return;

        const imageData = {
            url: imageUrlInput.value.trim(),
            name: imageNameInput.value.trim(),
            category: imageCategoryInput.value,
            date: new Date().toLocaleString()
        };

        images.push(imageData);

        renderGallery();

        imageForm.reset();
    });

    function removeImage(imageData) {
        images = images.filter(image => image !== imageData);
        renderGallery();
    }

    allFilter.addEventListener('click', () => renderGallery('All'));
    natureFilter.addEventListener('click', () => renderGallery('Nature'));
    cityFilter.addEventListener('click', () => renderGallery('City'));
    abstractFilter.addEventListener('click', () => renderGallery('Abstract'));

    sortBy.addEventListener('change', () => {
        const sortValue = sortBy.value;

        if (sortValue === 'nameAsc') {
            images.sort((a, b) => a.name.localeCompare(b.name));
        } else if (sortValue === 'nameDesc') {
            images.sort((a, b) => b.name.localeCompare(a.name));
        } else if (sortValue === 'dateAsc') {
            images.sort((a, b) => new Date(a.date) - new Date(b.date));
        } else if (sortValue === 'dateDesc') {
            images.sort((a, b) => new Date(b.date) - new Date(a.date));
        }

        renderGallery();
    });
});


// let images = []; // stores: url, name, category, date


// function createImageElement(imageData) //Uztaisa div container ar bildi, description un remove button.


// function renderGallery(filter = 'All') //parada jaunu izfiltreto array ar bildem


// function validateForm() //parbauda for errors vai ir jpg, png, gif, utt.


// imageForm.addEventListener('submit', function (e) // izveido objektu ar pieprasito form, adds the image to the array, izsauc renderGallary()


