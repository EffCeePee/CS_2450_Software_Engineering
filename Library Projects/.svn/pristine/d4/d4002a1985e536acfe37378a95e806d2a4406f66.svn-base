#include "Patron.h"

// ================================================
// Constructors and Destructor
// ================================================
Patron::Patron() {
	name = "";
	type = "";
	if (type == "adult") {
		allowedMedia = ADULT_LIMIT;
	} else if ("child") {
		allowedMedia = CHILD_LIMIT;
	}
}

Patron::Patron(string _name, string _type, vector<string> _media) {
	name = _name;
	type = _type;
	media = _media;
	if (type == "adult") {
		allowedMedia = ADULT_LIMIT;
	}
	else if ("child") {
		allowedMedia = CHILD_LIMIT;
	}
}

Patron::~Patron() {
	name = "";
	type = "";
	media.clear();
}

// ================================================
// Public Methods
// ================================================
/*
 * Verify that the patron has not reached the maximum number of checked out items
*/
bool Patron::canCheckout(string mediaType) {
	if (allowedMedia > media.size()) {
		if (type == "adult") {
			return true;
		} else if (mediaType == "childrens") {
			return true;
		}
	}
		
	return false;
}

/*
 *  Verify that the patron is of the desired type
*/
bool Patron::isType(string _type) {
	if (_type == type) {
		return true;
	} else {
		return false;
	}
}

/*
 *  Add the media to the list of items
*/
void Patron::assignMedia(string mediaName) {
	media.push_back(mediaName);
}

/*
 *  Remove the media from the list of items
*/
void Patron::removeMedia(string mediaName) {
	vector<string>::iterator position = find(media.begin(), media.end(), mediaName);
	if (position != media.end()) {
		media.erase(position);
	}
}

/*
 *  Print the patron name
*/
string Patron::printName() const {
	return name;
}

/*
 *  Print the patron media
*/
vector<string> Patron::printMedia() const {
	return media;
}

/*
 * Combine all the data members into a comma-delimited string and output to file
*/
string Patron::parseOutput() {
	string mediaItems = "";
	for (int i = 0; i < media.size(); ++i) {
		mediaItems += media[i] + ',';
	}
	mediaItems = mediaItems.substr(0, mediaItems.size() - 1); // Trim off the last comma

	return name + ',' + type + ',' + mediaItems + '\n';
}