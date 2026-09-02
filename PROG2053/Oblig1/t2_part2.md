# 2

## part 2


### What is the relative unit in CSS?

Explain what each CSS unit refers to (i.e., what it is relative to):
- em (x times the font size of the element)
- rem (same but relative to the font size of the root element)
- % (percent value of the size of the parent element)
- vh (1% of the viewport's height)
- vw (same but for width)
- vmin (the smaller of vh and vw)
- vmax the larger of vh and vw

### Calculate pixel values given

Calculate the pixel values given:
- Root (<html>) font-size = 18px
- Parent element font-size = 22px
- Parent container width = 500px
- Viewport size = 1440px × 900px


| Unit | CSS rule           | Px value                      |
| ---- | ------------------ | ----------------------------- |
| em   | font-size: 1.8em   | `22px * 1.8em = 39.6px`       |
| rem  | font-size: 2.5rem; | `18px * 2.5rem = 45px`        |
| %    | width: 60%;        | `0.6 * 500px = 300px`         |
| vh   | height: 7vh;       | `(0.01 * 7) * 900 = 63px`     |
| vw   | width: 8vw;        | `(0.01 * 8) * 1440 = 115.2px` |
| vmin | width: 6vmin;      | `(0.01 * 6) * 900 = 54px`     |
| vmax | width: 6vmax;      | `(0.01 * 6) * 1400 = 84px`    |

### Differance betwen .box1 and .box2 
box1 usses the default content-box value for box sizing which means that width and height only specify the element size, and
not the total outer size which includes borders and padding. 
Box2 uses border-box which forces the total width and height to be a set size. If padding or borders are applied it'l compress the elements inside to fit within the constraints.

Elements within other elements are by default placed in the top left corner, but this box sizing would "center it more" towards the middle if increased from 20 to 30 px.

# 3
