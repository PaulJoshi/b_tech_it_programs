function validate() {
	var score = 0;
	
	if(document.form.q1[1].checked) {
		score++;
		document.getElementById('q1-ver').innerHTML = 'Correct Answer';
	} else {
		document.getElementById('q1-ver').innerHTML = 'Wrong Answer';
	}
	
	if(document.form.q2[0].checked) {
		score++;
		document.getElementById('q2-ver').innerHTML = 'Correct Answer';
	} else {
		document.getElementById('q2-ver').innerHTML = 'Wrong Answer';
	}
	
	if(document.form.q3[0].checked) {
		score++;
		document.getElementById('q3-ver').innerHTML = 'Correct Answer';
	} else {
		document.getElementById('q3-ver').innerHTML = 'Wrong Answer';
	}
	
	if(document.form.q4[1].checked) {
		score++;
		document.getElementById('q4-ver').innerHTML = 'Correct Answer';
	} else {
		document.getElementById('q4-ver').innerHTML = 'Wrong Answer';
	}
	
	document.getElementById('score-header').innerHTML = 'YOUR SCORE';
	document.getElementById('score').innerHTML = 'Congratulations, you scored: ' + score;

	return false;
}