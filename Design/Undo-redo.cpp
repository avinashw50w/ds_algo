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
public:
	void push(EditorState state) {
		states.push_back(state);
	}
	EditorState pop() {
		return states[states.size() - 1];
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

	editor.restore(history.pop());

	cout << editor.getContent() << endl;
}