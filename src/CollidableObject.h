#ifndef SRC_COLLIDABLEOBJECT_H_
#define SRC_COLLIDABLEOBJECT_H_

class CollidableObject {
public:
	CollidableObject();
	CollidableObject(int xPos, int yPos, int width, int height);

	int x;
	int y;
	int w;
	int h;
};

#endif /* SRC_COLLIDABLEOBJECT_H_ */
