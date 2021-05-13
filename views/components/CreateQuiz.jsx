import axios from 'axios'
import React, { useState, useRef, useEffect } from 'react'
import ReactDOM from 'react-dom'

const QuizCreate = ({...props}) => {
  const [questions, setQuestions] = useState([])
  const [question, setQuestion] = useState('')
  const [answers, setAnswers] = useState(["Click to change the answer", "Click to change the answer", "Click to change the answer", "Click to change the answer"])
  const [image, setImage] = useState(null)
  const [modal, setModal] = useState([false, false, false, false])
  const [correct, setCorrect] = useState([false, false, false, false])
  const [timer, setTimer] = useState(0)
  const [message, setMessage] = useState('')
  const [hint, setHint] = useState('')
  const [page, setPage] = useState(0)
  const [name, setName] = useState('')
  const fileRef = useRef()

  useEffect(() => {
    if (page < questions.length) {
      setQuestion(questions[page].question)
      setTimer(questions[page].timer)
      setAnswers(questions[page].answers)
      setCorrect(questions[page].correct)
      setImage(questions[page].image)
      setHint(questions[page].hint)
    } else {
      setQuestion('')
      setHint('')
      setTimer(0)
      setAnswers(["Click to change the answer", "Click to change the answer", "Click to change the answer", "Click to change the answer"])
      setCorrect([false, false, false, false])
      setImage(null)
    }
  }, [page])

  const handleTimeChange = (event) => setTimer(event.target.value)
  const handleQuestionChange = (event) => setQuestion(event.target.value)
  const handleAnswerChange = (param) => {
    let auxModals = [...modal]
    auxModals[param] = !auxModals[param]

    setModal(auxModals)
  }
  const handleOnAnswerChange = (param, event) => {
    let auxAnswers = [...answers]
    auxAnswers[param] = event.target.value

    setAnswers(auxAnswers)
  }
  const handleFileInput = (event) => {
    const fileUploaded = event.target.files[0];
    setImage(fileUploaded)
  }
  const handleButtonRef = () => fileRef.current.click()
  const handleSaveButton = () => {
    if (answers[0] == "Click to change the answer" || hint == null || timer == null || question == null || answers[1] == "Click to change the answer" || answers[2] == "Click to change the answer" || answers[3] == "Click to change the answer") {
      setMessage("You can't save the question because you must complete the fields")
      setTimeout(() => setMessage(null), 5000)
    } else {
      let auxQuestions = questions;
      if (page == questions.length) {
        auxQuestions.push({
          question: question,
          timer: timer,
          answers: answers,
          correct: correct,
          hint: hint,
          image: image
        });
      } else {
        auxQuestions[page] = {
          question: question,
          timer: timer,
          answers: answers,
          correct: correct,
          hint: hint,
          image: image
        }
      }
      setQuestions(auxQuestions);

      setQuestion(null)
      setTimer(null)
      setAnswers(["Click to change the answer", "Click to change the answer", "Click to change the answer", "Click to change the answer"])
      setCorrect([false, false, false, false])
      setImage(null)
      setModal([false, false, false, false])
      setHint(null)
      setPage(questions.length)
    }
  }
  const changeStateButton = (param) => {
    let auxCorrect = [...correct]
    auxCorrect[param] = !auxCorrect[param]

    setCorrect(auxCorrect)
  }
  const handleHintChange = (event) => setHint(event.target.value)
  const handleNextPage = () => {
    if (page < questions.length) {
      setPage(page => page + 1)
      setQuestion(questions[page].question)
      setTimer(questions[page].timer)
      setAnswers(questions[page].answers)
      setCorrect(questions[page].correct)
      setImage(questions[page].image)
      setHint(questions[page].hint)
    } else {
      setQuestion(null)
      setTimer(null)
      setAnswers(["Click to change the answer", "Click to change the answer", "Click to change the answer", "Click to change the answer"])
      setCorrect([false, false, false, false])
      setImage(null)
      setModal([false, false, false, false])
      setHint(null)
    }
  }
  const handlePrevPage = () => {
    if (page > 0) {
      setPage(page => page - 1)
      setQuestion(questions[page].question)
      setTimer(questions[page].timer)
      setAnswers(questions[page].answers)
      setCorrect(questions[page].correct)
      setImage(questions[page].image)
      setHint(questions[page].hint)
    }
  }
  const handleCreateButton = async () => {
    if (name == '' && questions.length <= 0) {
      setMessage("You can't create the quiz because either you don't have the questions or the quiz title")
      setTimeout(() => setMessage(null), 5000)
    } else {
      let bodyFormData = new FormData()
      bodyFormData.append('title', name)
      bodyFormData.append('content', JSON.stringify(questions))
      
      await axios.post(`/quiz/create/${props.id}`, bodyFormData).then(() => {
        setMessage("You saved the quiz with success!")
        setTimeout(() => setMessage(null), 5000)
      })
    }
  }

  return (
    <>
      {
        message &&
        <div className="notification is-danger">
          {message}
        </div>
      }
      <div className="box">
        <div className="field">
          <label className="label">Put the question statement</label>
          <div className="control">
            <input className="input" type="text" value={question} placeholder="e.g. What will be the output" onChange={handleQuestionChange} required />
          </div>
        </div>
        <div className="field">
          <label className="label">Put a hint for the question</label>
          <div className="control">
            <input className="input" type="text" value={hint} placeholder="e.g. What will be the hint" onChange={handleHintChange} required />
          </div>
        </div>
        <div className="field">
          <label className="label">Select the time (in seconds)</label>
          <div className="control">
            <input className="input" type="number" value={timer} placeholder="e.g. 15" onChange={handleTimeChange} required />
          </div>
        </div>
        <div className="columns">
          <div className="column">
            <button className="button is-link my-2 is-fullwidth" onClick={() => handleAnswerChange(0)}>
              <strong>{answers[0]}</strong>
            </button>
            {
              modal[0] &&
              <div className="box">
                <div className="field">
                  <label className="label has-text-link">Quiz answer</label>
                  <div className="control">
                    <input className="input" type="text" placeholder="e.g. What will be the output" onChange={(event) => handleOnAnswerChange(0, event)} required />
                  </div>
                </div>

                <button className={`button ${correct[0] == false ? `is-success` : `is-danger`} has-text-centered`} onClick={() => changeStateButton(0)}>
                {
                  correct[0] == false ? `Mark as correct` : `Mark as wrong`
                }
                </button>
              </div>
            }
            <button className="button is-danger my-2 is-fullwidth" onClick={() => handleAnswerChange(1)}>
              <strong>{answers[1]}</strong>
            </button>
            {
              modal[1] &&
              <div className="box">
                <div className="field">
                  <label className="label has-text-danger">Quiz answer</label>
                  <div className="control">
                    <input className="input" type="text" placeholder="e.g. What will be the output" onChange={(event) => handleOnAnswerChange(1, event)} required />
                  </div>
                </div>
                <button className={`button ${correct[1] == false ? `is-success` : `is-danger`} has-text-centered`} onClick={() => changeStateButton(1)}>
                {
                  correct[1] == false ? `Mark as correct` : `Mark as wrong`
                }
                </button>
              </div>
            }
          </div>
          <div className="column">
            <button className="button is-warning my-2 is-fullwidth" onClick={() => handleAnswerChange(2)}>
              <strong>{answers[2]}</strong>
            </button>
            {
              modal[2] &&
              <div className="box">
                <div className="field">
                  <label className="label has-text-warning">Quiz answer</label>
                  <div className="control">
                    <input className="input" type="text" placeholder="e.g. What will be the output" onChange={(event) => handleOnAnswerChange(2, event)} required />
                  </div>
                </div>
                <button className={`button ${correct[2] == false ? `is-success` : `is-danger`} has-text-centered`} onClick={() => changeStateButton(2)}>
                {
                  correct[2] == false ? `Mark as correct` : `Mark as wrong`
                }
                </button>
              </div>
            }
            <button className="button is-success my-2 is-fullwidth" onClick={() => handleAnswerChange(3)}>
              <strong>{answers[3]}</strong>
            </button>
            {
              modal[3] &&
              <div className="box">
                <div className="field">
                  <label className="label has-text-success">Quiz answer</label>
                  <div className="control">
                    <input className="input" type="text" placeholder="e.g. What will be the output" onChange={(event) => handleOnAnswerChange(3, event)} required />
                  </div>
                </div>
                <button className={`button ${correct[3] == false ? `is-success` : `is-danger`} has-text-centered`} onClick={() => changeStateButton(3)}>
                {
                  correct[3] == false ? `Mark as correct` : `Mark as wrong`
                }
                </button>
              </div>
            }
          </div>
        </div>

        <input hidden type="file" ref={fileRef} onChange={handleFileInput} />
        <button className="button is-fullwidth is-primary" onClick={handleButtonRef}>
          <strong>Upload an image for the question</strong>
        </button>
      </div>

      <div className="columns">
        <div className="column">
          {
            (page > 0) &&
            <button className="button is-light is-small is-pulled-left mx-1" onClick={handlePrevPage}><strong>Previous question</strong></button>
          }
          {
            (page < questions.length) &&
            <button className="button is-light is-small is-pulled-left mx-1" onClick={handleNextPage}><strong>Next question</strong></button>
          }
        </div>
        <div className="column">
          <button className="button is-black is-small is-pulled-right mx-1" onClick={handleSaveButton}>Save question</button>
        </div>
      </div>

      <div className="box">
        <div className="field">
          <label className="label">Enter a name for the quiz</label>
          <div className="control">
            <input className="input" type="text" value={name} placeholder="e.g. What will be the output" onChange={(event) => setName(event.target.value)} required />
          </div>
        </div>
      </div>

      <button className="button is-success is-small is-fullwidth" onClick={handleCreateButton}>
        <strong>Create the new quiz</strong>
      </button>
    </>
  )
}

if (document.getElementById('create-quiz')) {
  const props = Object.assign({}, document.getElementById('create-quiz').dataset);
  ReactDOM.render(<QuizCreate  {...props} />, document.getElementById('create-quiz'))
}