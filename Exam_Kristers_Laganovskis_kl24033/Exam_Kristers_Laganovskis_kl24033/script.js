const subHeads = ['radīt emocijas.', 'iedvesmot rīcībai.', 'uzlabot biznesu.', 'piesaistīt uzmanību.'];
let displayIdx = 0;

setInterval(() => {
    document.getElementById('text-swap').innerHTML = subHeads[displayIdx];
    displayIdx += 1;
    if (displayIdx >= subHeads.length) {
        displayIdx = 0;
    }
}, 1000);

document.addEventListener("DOMContentLoaded", function() {
    const projects = document.querySelectorAll(".project");

    projects.forEach(project => {
        const overlay = project.querySelector(".overlay");

        project.addEventListener("mouseenter", () => {
            overlay.style.opacity = "1";
        });

        project.addEventListener("mouseleave", () => {
            overlay.style.opacity = "0";
        });
    });
});

fetch('services.json')
.then(response => response.json())
.then(data => {
    const serviceList = document.getElementById("serviceList");
    const selectedList = document.getElementById("selectedList");
    const totalSum = document.getElementById("totalSum");
    const clearSelection = document.getElementById("clearSelection");

    const selectedServices = [];

    data.services.forEach((service) => {
        const li = document.createElement("li");
        li.dataset.price = service.price;
        li.dataset.name = service.name;
        li.textContent = `${service.name} - ${service.price} EUR`;
        serviceList.appendChild(li);
        
        li.addEventListener("click", () => {
            if (!selectedServices.includes(service.name)) {
                selectedServices.push(service.name);
                addSelectedService(service.name, service.price);
                updateTotal();
            }
        });
    });

    function addSelectedService(name, price) {
        const li = document.createElement("li");
        li.dataset.price = price;
        li.dataset.name = name;

        const text = document.createElement("span");
        text.textContent = `${name}`;

        li.appendChild(text);
        selectedList.appendChild(li);
    }

    function updateTotal() {
        let total = 0;
        selectedList.querySelectorAll("li").forEach(li => {
            total += parseFloat(li.dataset.price);
        });

        const currentTotal = parseFloat(totalSum.textContent) || 0;

        anime({
            targets: '#totalSum',
            innerHTML: [currentTotal, total],
            easing: 'linear',
            round: 1,
            duration: 400,
            update: function(anim) {
                document.getElementById('totalSum').textContent = anim.animations[0].currentValue.toFixed(2);
            }
        });
    }

    clearSelection.addEventListener("click", () => {
        selectedServices.length = 0;
        selectedList.innerHTML = ""
        totalSum.textContent = "0.00";
    });
})

const form = document.getElementById('contactForm');
form.addEventListener('submit', function(event) {
    let valid = true;

    const name = document.getElementById('name').value;
    const nameError = document.getElementById('nameError');

    if (name.length < 3) {
        nameError.textContent = 'Vārdā ir jābūt vismaz 3 burtiem.';
        valid = false;
    } else {
        nameError.textContent = '';
    }

    const number = document.getElementById('number').value;
    const numberError = document.getElementById('numberError');
    const number_are_there = /^[0-9+]+$/;

    if (!number_are_there.test(number)) {
        numberError.textContent = 'Telefona numurs var sastāvēt no tikai cipariem vai "+".';
        valid = false;
    } else {
        numberError.textContent = '';
    }

    const email = document.getElementById('email').value;
    const emailError = document.getElementById('emailError');
    const email_is_there = /^[^\s@]+@[^\s@]+\.[^\s@]+$/;

    if (!email_is_there.test(email)) {
        emailError.textContent = 'E-pasta adresei ir jābūt ar "@example.com".';
        valid = false;
    } else {
        emailError.textContent = '';
    }

    const message = document.getElementById('message').value;
    const messageError = document.getElementById('messageError');

    if (message.length < 5 || message.length > 600) {
        messageError.textContent = 'Ziņa ir jābūt no 5 lidz 600 burtiem.';
        valid = false;
    } else {
        messageError.textContent = '';
    }

    if (!valid) {
        event.preventDefault();
    }
});