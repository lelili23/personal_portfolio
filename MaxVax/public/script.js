async function returnText() {
    const zipcode = document.getElementById('userInput').value.trim();
    if (zipcode.length !== 5 || isNaN(zipcode)) {
        alert('Please enter a valid 5-digit ZIP code.');
        return;
    }

    try {
        const matchingLocations = await fetchVaccineLocationsByZipcode(zipcode);
        displayResults(matchingLocations);
    } catch (error) {
        console.error('Error:', error);
        alert('An error occurred. Please try again.');
    }
}

async function fetchVaccineLocationsByZipcode(zipcode) {
    try {
        const response = await fetch(`/getLocations?zipcode=${zipcode}`);
        if (!response.ok) {
            throw new Error(`Network response was not ok: ${response.statusText}`);
        }

        const allData = await response.json();
        const limitedLocations = allData.slice(0, 3);
        return limitedLocations;
    } catch (error) {
        console.error('Error fetching data:', error);
    }
}


function displayResults(locations) {
    const resultsDiv = document.getElementById('results');
    resultsDiv.innerHTML = ''; // Clear previous results

    if (locations.length === 0) {
        resultsDiv.innerHTML = '<p>No locations found for the provided ZIP code.</p>';
        return;
    }

    locations.forEach(location => {
        const locationDiv = document.createElement('div');
        locationDiv.classList.add('result');
        locationDiv.innerHTML = `
        <div id="location">
            <h3>${location.loc_name}</h3>
            <p>${location.loc_admin_street1}, ${location.loc_admin_city}, ${location.loc_admin_state} ${location.loc_admin_zip}</p>
            <p>Phone: ${location.loc_phone}</p>
            <p>Website: <a href="${location.web_address}" target="_blank">${location.web_address}</a></p>
        </div>
            `;
        resultsDiv.appendChild(locationDiv);
    });
}


function returnAge(){
    var ag = document.getElementById("userAge").value;
  
    if(ag<18 && ag>=12){
      document.getElementById('age').innerHTML = "You are en route to get the Pfizer-BioNTech!";
    }
    else if (ag>=18){
      document.getElementById('age').innerHTML = "You are eligible to get either the Johnson & Johnson, or the Moderna!";
    }
    else if (ag<12){
      document.getElementById('age').innerHTML = "Your vax is on the way! Expect it mid-winter.  In the meantime, continue to wear a mask indoors and in crowded spaces.";
    }
}
  