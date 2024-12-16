// execute the script when the HTML document has been completely parsed
document.addEventListener("DOMContentLoaded", (event) => {
	// Select DOM elements
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

	let images = [];  // Array to store image data

	// Function to create image element, supplement the code to set the necessary attributes of the image card in the gallery
	function createImageElement(imageData) {
		const imageItem = document.createElement('div');
		
		const img = document.createElement('img'); 
		
		imageItem.appendChild(img);
		
		const removeButton = document.createElement('button');

		removeButton.addEventListener('click', () => removeImage(imageData));
		imageItem.appendChild(removeButton);

		const imageInfo = document.createElement('p');

		imageItem.appendChild(imageInfo);
		
		return imageItem;
	}

	// Function to render images to the gallery
	function renderGallery(filter) {
		gallery.innerHTML = ''; // clean the gallery
		// filter the images according to the filter parameter, run the function createImageElement for each image and append generated images to the gallery

	}

	// Function to validate the form
	function validateForm() {
		let valid = true;

		// Clear previous error messages
		urlError.textContent = '';
		nameError.textContent = '';
		categoryError.textContent = '';

		// Validate Image URL (must end with .jpg, .png, .gif, or .svg), in case on error, display error message in urlError


		// Validate Image Name (cannot be empty), in case on error, display error message in nameError


		// Validate Category (must be selected), in case on error, display error message in categoryError


		return valid;
	}

	// Function to add an image
	imageForm.addEventListener('submit', function (e) {
		e.preventDefault(); // cancel form submission
		
		// Validate the fields with the function validateForm(), stop processing if validation fails

		// Create image data object

		// Add the image data to the array images
		
		// Render the updated gallery

		// Reset the form
	});

	// Function to remove an image from the array images and from the gallery HTML
	function removeImage(imageData) {

	}

	// Filter buttons
	allFilter.addEventListener('click', () => {
		renderGallery('All');
	});

	// Add event listeners to other buttons
	
	// Sorting functionality
	sortBy.addEventListener('change', () => {
		// Get selected option from the drop-down list sortBy
		
		// Sort the array images according to the selected option

		// Render the gallery
	});

});