/*
implement undo redo functionality in a editor

use momento design pattern
 */

class Editor {
	string content;
public:
	string getContent() { return content; }
	void setContent(string content) { this->content = content; }

	EditorState createState() {
		return new EditorState(content);
	}

	void restore(EditorState state) {
		content = state.getContent();
	}
};

class EditorState {
	static string content;
public:
	EditorState(string content) : content(content) {}
	string getContent() { return content; }
};

class History {
	vector<EditorState> states;
	int top = 0;
public:
	void push(EditorState state) {
		states.push_back(state);
		top++;
	}
	EditorState undo() {
		if (top == 0) return NULL;
		return states[--top];
	}
	EditorState redo() {
		return states[++top];
	}
};

int main() {
	Editor editor = new Editor();
	History history = new History();

	editor.setContent("a");
	history.push(editor.createState());

	editor.setContent("b");
	history.push(editor.createState());

	editor.setContent("b");
	history.push(editor.createState());

	editor.restore(history.undo());

	cout << editor.getContent() << endl;

	editor.restore(history.redo());

	cout << editor.getContent() << endl;
}