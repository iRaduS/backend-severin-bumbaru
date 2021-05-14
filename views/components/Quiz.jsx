import axios from 'axios';
import React, { useState } from 'react'
import ReactDOM from 'react-dom'
import './quiz.css'

const Quiz = ({...props}) => {
  const [current, setCurrent] = useState(0);
  const [progress, setProgress] = useState(0);
  const [seconds, setSeconds] = useState(null);
  const [correct, setCorrect] = useState(0);
  const [bad, setBad] = useState(0);
  const [finish, setFinish] = useState(false);
  const [credits, setCredits] = useState(0);
  const [fifty, setFifty] = useState(JSON.parse(props.fifty));
  const [hint, setHint] = useState(JSON.parse(props.hint));
  const [showHint, setShowHint] = useState(false);
  const [bhint, setShowBHint] = useState(true);
  const [bgambit, setShowBGambit] = useState(true);
  const [answers, setAnswers] = useState([true, true, true, true]);
  let timer;

  React.useEffect(() => {
    console.log(JSON.parse(props.quiz));
  }, [])

  React.useEffect(() => {
    if (seconds > 0 && seconds != null) {
      timer = setTimeout(() => {
        setProgress(progress + 100 / JSON.parse(props.quiz).details[current].timer)
        setSeconds(seconds - 1)
      }, 1000);
    } else if (seconds == 0 || seconds == -1) {
      if (seconds == 0) {
        setCredits(credits - 50);
        setBad(bad + 1);
      }
      if (current != JSON.parse(props.quiz).details.length - 1) {
        setCurrent(current + 1);
      } else {
        setFinish(true);
      }
    }
  }, [seconds])

  React.useEffect(() => {
    (async () => {
      let userForm = new FormData();
      userForm.append('fifty', fifty)
      userForm.append('hint', hint)
      await axios.post(`/quiz/user/${props.user}`, userForm)
    })();
  }, [fifty, hint]);

  React.useEffect(() => {
    if (finish) {
      (async () => {
        let creditForm = new FormData();
        creditForm.append('coins', credits)
        creditForm.append('fifty', fifty)
        creditForm.append('hint', hint)
        await axios.post(`/quiz/finish/${props.user}`, creditForm)
      })();
    }
  }, [finish])

  React.useEffect(() => {
    setSeconds(JSON.parse(props.quiz).details[current].timer);
    setProgress(0);
    setShowHint(false);
    setAnswers([true, true, true, true])
  }, [current])

  const checkAnswer = (id) => {
    if (JSON.parse(props.quiz).details[current].correct[id]) {
      setCredits(Math.round(credits + 100 / (JSON.parse(props.quiz).details[current].timer - seconds)))
      setCorrect(correct + 1);
    }
    else {
      setCredits(credits - 50);
      setBad(bad + 1);
    }

    clearTimeout(timer);
    setSeconds(-1);
  }
  const handleHintChange = async () => {
    if (hint) {
      setHint(hint - 1);
      setShowHint(true);
      setShowBHint(false);
    }
  }

  const handleGambitChange = async () => {
    if (fifty) {
      setFifty(fifty - 1);
      setShowBGambit(false);

      const auxAnswers = [...answers];
      const chances = Math.floor(Math.random() * 3);
      if (JSON.parse(props.quiz).details[current].correct[0]) {
        switch (chances) {
          case 0: auxAnswers[1] = false; auxAnswers[2] = false; break;
          case 1: auxAnswers[1] = false; auxAnswers[3] = false; break;
          case 2: auxAnswers[3] = false; auxAnswers[2] = false; break;
        }
      } else if (JSON.parse(props.quiz).details[current].correct[1]) {
        switch (chances) {
          case 0: auxAnswers[0] = false; auxAnswers[2] = false; break;
          case 1: auxAnswers[0] = false; auxAnswers[3] = false; break;
          case 2: auxAnswers[3] = false; auxAnswers[2] = false; break;
        }
      } else if (JSON.parse(props.quiz).details[current].correct[2]) {
        switch (chances) {
          case 0: auxAnswers[0] = false; auxAnswers[1] = false; break;
          case 1: auxAnswers[0] = false; auxAnswers[3] = false; break;
          case 2: auxAnswers[3] = false; auxAnswers[1] = false; break;
        }
      } else if (JSON.parse(props.quiz).details[current].correct[3]) {
        switch (chances) {
          case 0: auxAnswers[0] = false; auxAnswers[1] = false; break;
          case 1: auxAnswers[0] = false; auxAnswers[2] = false; break;
          case 2: auxAnswers[2] = false; auxAnswers[1] = false; break;
        }
      }
      setAnswers(auxAnswers);
    }
  }

  return (
    <>
      {
        finish == true ? 
        <section class="hero is-fullheight is-link is-bold">
          <div class="hero-body">
            <div class="container has-text-centered">
              <h1 class="title">⭐️ You finished ⭐️</h1>
              <button className="button is-danger mb-2" onClick={() => window.location.href = `http://${location.host}/Group/show/${props.groupid}`}>
                Go back to quizzes
              </button>
              <div class="tile is-ancestor has-text-centered">
                <div class="tile is-parent is-dark">
                  <article class="tile is-child box has-background-success">
                    <p class="title">{correct}</p>
                    <p class="subtitle">Correct Answers</p>
                  </article>
                </div>
                <div class="tile is-parent">
                <article class="tile is-child box has-background-success">
                    <p class="title">{bad}</p>
                    <p class="subtitle">Bad Answers</p>
                  </article>
                </div>
                <div class="tile is-parent">
                  <article class="tile is-child box has-background-success">
                    <p class="title">{credits}</p>
                    <p class="subtitle">Credits</p>
                  </article>
                </div>
              </div>
            </div>
          </div>
        </section>
        :
      <div class="container is-max-desktop">
        <article class="message">
          <div class="message-header">
              <p>Question {current + 1} out of {JSON.parse(props.quiz).details.length}</p>
          </div>
          <div class="message-body">
            <h2 class="subtitle"><strong>{JSON.parse(props.quiz).details[current].question}</strong></h2>
          </div>
          {
            seconds != 0 && 
            <div class="has-text-centered has-text-danger is-flex-inline"><strong>Remaining time for the question</strong> {seconds} secunde(a)</div>
          }
          <progress class="progress is-danger is-large" value={progress} max="100"></progress>
          <div class="px-3 columns 1">
            <div class="column is-half">
              {
                answers[0] == true && 
                <button class="button button--custom is-link" onClick={() => checkAnswer(0)}>{JSON.parse(props.quiz).details[current].answers[0]}</button>
              }
            </div>
            <div class="column is-half">
              {
                answers[1] == true && 
                <button class="button button--custom is-danger" onClick={() => checkAnswer(1)}>{JSON.parse(props.quiz).details[current].answers[1]}</button>
              }
            </div>
          </div>
          <div class="px-3 columns 2">
              <div class="column is-half">
                  {
                    answers[2] == true &&
                    <button class="button button--custom is-warning" onClick={() => checkAnswer(2)}>{JSON.parse(props.quiz).details[current].answers[2]}</button>
                  }
              </div>
              <div class="column is-half">
                {
                  answers[3] == true &&
                  <button class="button button--custom is-success" onClick={() => checkAnswer(3)}>{JSON.parse(props.quiz).details[current].answers[3]}</button>
                }
              </div>
          </div>
        </article>

        { showHint == true &&
          <div class="notification is-link">
            {JSON.parse(props.quiz).details[current].hint}
          </div>
        }
        {
          bgambit == true &&
          <button className="mx-1 button is-black is-pulled-left" onClick={handleGambitChange}><strong>Use a Gambit</strong> <span class="ml-1 tag is-success">{fifty} owned</span></button>
        }
        {
          bhint == true &&
          <button className="mx-1 button is-black is-pulled-left" onClick={handleHintChange}><strong>Use a Riddle</strong> <span class="ml-1 tag is-success">{hint} owned</span></button>
        }
        <small class="mx-1">*The power-ups can be used only once in a quiz</small>
      </div>
      }
    </>
  );
}

if (document.getElementById('quiz')) {
  const props = Object.assign({}, document.getElementById('quiz').dataset)
  ReactDOM.render(<Quiz {...props} />, document.getElementById('quiz'))
}