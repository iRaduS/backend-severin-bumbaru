import axios from 'axios'
import React from 'react'
import ReactDOM from 'react-dom'

const ListQuiz = ({...props}) => {  
  const handleStartQuiz = (id) => {
    window.location.href = `http://${location.host}/quiz/show/${props.groupid}/${id}`
  }
  const handleDelete = async (id) => {
    await axios.delete(`/quiz/remove/${props.group_id}/${id}`).then((val) => {
      window.location.reload()
    })
  }
  return (
    <div className="mt-3">
      <div className="box is-flex is-justify-content-center is-align-items-center">
        <table className="table is-fullwidth">
          <thead>
            <tr>
              <th><abbr title="Quiz name">Quiz name</abbr></th>
              <th><abbr title="Options">Options</abbr></th>
            </tr>
          </thead>
          <tbody>
            {
              JSON.parse(props.quiz).map((value, index) => (
                <tr key={index}>
                  <th>{value.name}</th>
                  <td>
                    <button className="button is-small is-info mx-1" onClick={() => handleStartQuiz(value.id)}>Start</button>
                    {
                      props.role == 2 &&
                      <button className="button is-small is-danger mx-1" onClick={() => handleDelete(value.id)}>Delete</button>
                    }
                  </td>
                </tr>
              ))
            }
          </tbody>
        </table>
      </div>
    </div>
  );
}

if (document.getElementById('list-quiz')) {
  const props = Object.assign({}, document.getElementById('list-quiz').dataset);
  ReactDOM.render(<ListQuiz {...props} />, document.getElementById('list-quiz'))
}