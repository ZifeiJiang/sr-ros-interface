sr\_grasp
=========

Tools for running grasps (moveit\_msgs/Grasp) on the Shadow Hand.
Handles pre and main grasps, interpolating the motion over a
configuarable amount, using the position controllers. Can optionally
stop the grasp on contact with the finger tactile sensors.

Also contains:

-  grasp\_planner - A simple grasp planner for the shadow hand.
-  isr\_grasp.utils - A python library.

grasp
-----

Quick Start
~~~~~~~~~~~

Start either your real Shadow Hand (with position controllers) or a
simulated one:

.. code:: sh

    roslaunch sr_hand gazebo_hand.launch

Then start the grasp node:

.. code:: sh

    rosrun sr_grasp grasp

Now start the quick grasp tool, which provides a quick command line way
to run a full hand grasp:

.. code:: sh

    rosrun sr_grasp quick_grasp
    [INFO] [WallTime: 1420469735.467177] [2088.184000] Loaded grasps from file: /home/hand/indigo_ws/src/shadow_robot/sr_grasp/resource/grasps.yaml
    [INFO] [WallTime: 1420469735.467525] [2088.184000] Looking for hand...
    [WARN] [WallTime: 1420469738.040228] [2089.002000] No tactile topic found. This is normal for a simulated hand
    [INFO] [WallTime: 1420469738.040807] [2089.002000] Found

    Grasps:
    0 - Power Grasp Vertical
    1 - Pinch Horizontal
    2 - Basic full grab
    Current grasp: Power Grasp Vertical
    Number select grasp, z zero hand, g grasp, p pre-grasp, q quit
    : 

Working with grasp files.
~~~~~~~~~~~~~~~~~~~~~~~~~

Sets of grasps can be stored in YAML files containing a top level array
of moveit\_msgs/Grasp objects serialised to YAML the same way rostopic
does. Although most of the fields are optional you must have an id and
will need at least one pre-grasp posture and grasp posture. sr\_grasp
contains some example files in the resource directory.

quick grasp reads it's ~grasps\_file param to get the file name of
grasps to use, defaulting to grasps.yaml in the sr\_grasp package. So to
use another file:

::

    rosrun sr_grasp quick_grasp _grasps_file:=foo.yaml

You can use the n command to create a new grasp using the current hands
pose as the grasp pose. The s command will re-write the file with the
current list of grasps.

Actionlib
~~~~~~~~~

The main interface to the node is via actionlib, it exposes the
sr\_robot\_msgs/Grasp action on the grasp/ topic. See the quick\_grasp
script for a python example of using this interface.

grasp\_planner
--------------

Node implementing the sr\_robot\_msgs/PlanGrasp action to generate
grasps. Currently returns a single, hardcoded grasp.

sr\_grasp.utils
---------------

Python lib. Exports a mk\_grasp function for quick generation of
moveit\_msgs/Grasp messages.

.. code:: py

    from sr_grasp.utils import mk_grasp

    grasp = mk_grasp({
        'LFJ3': 1.4, 'RFJ3': 1.4, 'MFJ3': 1.4, 'FFJ3': 1.4,
        'LFJ0': 2.0, 'RFJ0': 2.0, 'MFJ0': 2.0, 'FFJ0': 2.0,
        'THJ1': 0.4, 'THJ2': 0.36, 'THJ3': 0.2, 'THJ4': 1.23, 'THJ5': 0.06, 
    })

Converting sr\_hand XML grasps
------------------------------

sr\_hand has some grasps classes, interpolater and gui that work with an
XML file found in sr\_hand/scripts/sr\_hand/grasps.xml. You can convert
them to new style moveit messages in YAML using:

::

    rosrun sr_grasp convert_xml.py sr_hand/scripts/sr_hand/grasps.xml > converted.yaml

Then load them up to play with:

::

    rosrun sr_grasp quick_grasp _grasps_file:=converted.yaml

