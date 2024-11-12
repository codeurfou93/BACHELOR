let tasks = []; 
let filter = 'all';

window.onload = function() {
    loadTasks();
    renderTasks();
};

function saveTasks() {
    localStorage.setItem('tasks', JSON.stringify(tasks));
}

function loadTasks() {
    const storedTasks = localStorage.getItem('tasks');
    if (storedTasks) {
        tasks = JSON.parse(storedTasks);
    }
}

function addTask() {
    const taskName = document.getElementById('taskInput').value.trim();
    if (taskName === "") return alert("Veuillez entrer une tâche.");
    tasks.push({ name: taskName, status: 'todo' });
    document.getElementById('taskInput').value = ""; 
    saveTasks(); 
    renderTasks();
}

function renderTasks() {
    const taskList = document.getElementById('taskList');
    taskList.innerHTML = ''; 

    tasks
        .filter(task => filter === 'all' || task.status === filter)
        .forEach((task, index) => {
            const taskItem = document.createElement('li');
            taskItem.className = "list-group-item d-flex justify-content-between align-items-center";

            const taskNameSpan = document.createElement('span');
            taskNameSpan.className = `task-name ${task.status === 'done' ? 'done' : ''}`;
            taskNameSpan.textContent = task.name;

            const toggleButton = document.createElement('button');
            toggleButton.className = `btn btn-sm ${task.status === 'todo' ? 'btn-success' : 'btn-warning'}`;
            toggleButton.textContent = task.status === 'todo' ? 'Marquer comme fait' : 'Revenir à faire';
            toggleButton.onclick = () => toggleTaskStatus(index);

            const deleteButton = document.createElement('button');
            deleteButton.className = "btn btn-sm btn-danger ms-2";
            deleteButton.textContent = "Supprimer";
            deleteButton.onclick = () => deleteTask(index);

            taskItem.appendChild(taskNameSpan);
            taskItem.appendChild(toggleButton);
            taskItem.appendChild(deleteButton);
            taskList.appendChild(taskItem);
        });
}

function toggleTaskStatus(index) {
    tasks[index].status = tasks[index].status === 'todo' ? 'done' : 'todo';
    saveTasks(); 
    renderTasks();
}

function deleteTask(index) {
    tasks.splice(index, 1); 
    saveTasks(); 
    renderTasks();
}

function filterTasks(newFilter) {
    filter = newFilter;
    renderTasks();
}

renderTasks();
